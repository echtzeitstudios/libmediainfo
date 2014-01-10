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

void NativeMediaInfo::Init(Handle<Object> target){
  Local<FunctionTemplate> tpl = FunctionTemplate::New(New);
  tpl->SetClassName(String::NewSymbol("NativeMediaInfo"));
  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  // Prototype
  tpl->PrototypeTemplate()->Set(String::NewSymbol("feed"),
      FunctionTemplate::New(Feed)->GetFunction());

  Persistent<Function> constructor = Persistent<Function>::New(tpl->GetFunction());
  target->Set(String::NewSymbol("NativeMediaInfo"), constructor);
}

Handle<Value> NativeMediaInfo::New(const Arguments& args) {
    NanScope();

    NativeMediaInfo* obj = new NativeMediaInfo();
    MediaInfoLib::MediaInfo hand;

    obj->medinfo = &hand;
    obj->medinfo->Option(__T("Info_Version"), __T("0.7.65;libmediainfo-native;0.0.1"));
    obj->medinfo->Option(__T("Demux"), __T("All"));
    obj->medinfo->Open_Buffer_Init();
    obj->medinfo->Option(__T("File_IsSeekable"), __T("0"));
    
    obj->Wrap(args.This());
    NanReturnValue(args.This());
}

Handle<Value> NativeMediaInfo::Feed(const Arguments& args) {
    NanScope();

    assert(Buffer::HasInstance(args[0]));

    // return undef to keep feeding
    NativeMediaInfo* obj = ObjectWrap::Unwrap<NativeMediaInfo>(args.This());

    const unsigned char* buf = (unsigned char*)node::Buffer::Data(args[0]);
    size_t test = obj->medinfo->Open_Buffer_Continue(
        buf, 
        node::Buffer::Length(args[0]) 
    );
    
    if( test & 0x01 ) {
        // we're complete... info should be around
        obj->medinfo->Open_Buffer_Finalize();

        Local<Object> retobj = Object::New();
/*
        for (size_t StreamKind=MediaInfoLib::Stream_General; StreamKind<MediaInfoLib::Stream_Max; StreamKind++) {
            Local<Array> arr = Array::New();
            retobj->Set(
                String::New((char*)obj->medinfo->Get((MediaInfoLib::stream_t)StreamKind, 0, __T("StreamKind/String")).c_str()), 
                arr
            ); 
            for (size_t StreamPos=0; StreamPos<obj->medinfo->Count_Get((MediaInfoLib::stream_t)StreamKind); StreamPos++) {
                Local<Object> info = Object::New();
                arr->Set(StreamPos, info);
                for (size_t ParameterPos=0; ParameterPos<obj->medinfo->Count_Get((MediaInfoLib::stream_t)StreamKind, StreamPos); StreamPos++)
                {
                    info->Set(
                        String::New((char*)obj->medinfo->Get((MediaInfoLib::stream_t)StreamKind, StreamPos, ParameterPos, MediaInfoLib::Info_Name).c_str()),
                        String::New((char*)obj->medinfo->Get((MediaInfoLib::stream_t)StreamKind, StreamPos, ParameterPos, MediaInfoLib::Info_Text).c_str())
                    );
                }
            }
        }
*/
        NanReturnValue(scope.Close(retobj));
    } else {
        // keep going!
        NanReturnUndefined();
    }
}


