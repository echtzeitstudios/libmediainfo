#include <node.h>
#include <v8.h>

#include "MediaInfo.h"

using namespace node;
using namespace v8;

Handle<Value> Method(const Arguments& args) {
    HandleScope scope;
    // MediaInfoLib::MediaInfo::Option("Info_Version", "0.7.65;libmediainfo-node;0.0.1"); 
    MediaInfoLib::MediaInfo hand;
    hand.Option_Static("Info_Version", "0.7.65;libmediainfo-node;0.0.1"); 
    return scope.Close(String::New("world"));
}

void init(Handle<Object> target) {
      NODE_SET_METHOD(target, "hello", Method);
}

NODE_MODULE(binding, init);
