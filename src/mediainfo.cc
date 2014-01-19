#include <node.h>
#include <v8.h>

#include <string>
#include <iostream>

#include <nan.h>
#include "MediaInfo/MediaInfo.h"
#include "mediainfo.h"

using namespace node;
using namespace v8;

NativeMediaInfo::NativeMediaInfo() {};
NativeMediaInfo::~NativeMediaInfo() {};

static Persistent<Function> nativemediainfo_constructor;

void NativeMediaInfo::Init(Handle<Object> target){
  Local<FunctionTemplate> tpl = FunctionTemplate::New(New);
  tpl->SetClassName(NanSymbol("NativeMediaInfo"));
  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  // Prototype
  tpl->PrototypeTemplate()->Set(NanSymbol("feed"),
      FunctionTemplate::New(Feed)->GetFunction());

  Local<Function> constructor = tpl->GetFunction();
  NanAssignPersistent(Function, nativemediainfo_constructor, constructor);
  target->Set(NanSymbol("NativeMediaInfo"), constructor);
}

NAN_METHOD(NativeMediaInfo::New) {
    NanScope();

    NativeMediaInfo* obj = new NativeMediaInfo();

    obj->medinfo = new MediaInfoLib::MediaInfo();
    obj->medinfo->Option(__T("Info_Version"), __T("0.7.65;libmediainfo-native;0.0.1"));
    obj->medinfo->Option(__T("File_IsSeekable"), __T("0"));
    obj->medinfo->Open_Buffer_Init();
    
    obj->Wrap(args.This());
    NanReturnValue(args.This());
}

NAN_METHOD(NativeMediaInfo::Feed) {
    NanScope();

    assert(Buffer::HasInstance(args[0]));

    // return undef to keep feeding
    NativeMediaInfo* obj = ObjectWrap::Unwrap<NativeMediaInfo>(args.This());

    const unsigned char* buf = (unsigned char*)node::Buffer::Data(args[0]);
    size_t test = obj->medinfo->Open_Buffer_Continue(
        buf, 
        node::Buffer::Length(args[0]) 
    );
    
    if( test == 0 ) {
        // we're complete... info should be around
        obj->medinfo->Open_Buffer_Finalize();

        Local<Object> retobj = Object::New();
        for (size_t StreamKind=MediaInfoLib::Stream_General; StreamKind < MediaInfoLib::Stream_Max; StreamKind++) {
            Local<Array> arr = Array::New();
            std::wstring StreamKindName = obj->medinfo->Get((MediaInfoLib::stream_t)StreamKind, 0, L"StreamKind");

            std::wcout << StreamKindName << "\n";

            char stream_kind_name_buf[ StreamKindName.size() ];
            wcstombs(stream_kind_name_buf, StreamKindName.c_str(), sizeof(stream_kind_name_buf));
            retobj->Set(
                String::New(stream_kind_name_buf, sizeof(stream_kind_name_buf)), 
                arr
            );

            for (size_t StreamPos=0; StreamPos < (size_t)obj->medinfo->Count_Get((MediaInfoLib::stream_t)StreamKind); StreamPos++) {
                Local<Object> info = Object::New();
                arr->Set(StreamPos, info);
                for (size_t ParameterPos=0; ParameterPos < (size_t)obj->medinfo->Count_Get((MediaInfoLib::stream_t)StreamKind, StreamPos); ParameterPos++)
                {
                    std::wstring Key = obj->medinfo->Get((MediaInfoLib::stream_t)StreamKind, StreamPos, ParameterPos, MediaInfoLib::Info_Name);
                    std::wstring Val = obj->medinfo->Get((MediaInfoLib::stream_t)StreamKind, StreamPos, ParameterPos, MediaInfoLib::Info_Text);

                    char key_buf[ Key.size() ];
                    char val_buf[ Val.size() ];
                    wcstombs(key_buf, Key.c_str(), sizeof(key_buf));
                    wcstombs(val_buf, Val.c_str(), sizeof(val_buf));
                    if(sizeof(val_buf) == 0){
                        continue;
                    }
                    info->Set(
                        String::New(key_buf, sizeof(key_buf)),
                        String::New(val_buf, sizeof(val_buf))
                    );
                }
            }
        }

        delete obj->medinfo;

        NanReturnValue(retobj);
    } else {
        // keep going!
        NanReturnUndefined();
    }
}


