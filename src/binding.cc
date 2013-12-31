#include <node.h>
#include <v8.h>

#include <string>
#include <iostream>
#include "MediaInfo/MediaInfo.h"

using namespace node;
using namespace v8;


Handle<Value> Method(const Arguments& args) {
    HandleScope scope;
    MediaInfoLib::MediaInfo hand;
    hand.Option(__T("Info_Version"), __T("0.7.65;libmediainfo-node;0.0.1")); 
    return scope.Close(String::New("world"));
}

void init(Handle<Object> target) {
      NODE_SET_METHOD(target, "hello", Method);
}

NODE_MODULE(binding, init);
