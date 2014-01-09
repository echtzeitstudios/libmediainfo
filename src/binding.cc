#include <node.h>

#include "mediainfo.h"

using namespace v8;

void InitAll(Handle<Object> exports) {
  NativeMediaInfo::Init(exports);
}

NODE_MODULE(binding, InitAll)
