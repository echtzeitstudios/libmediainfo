#ifndef NATIVEMEDIAINFO_H
#define NATIVEMEDIAINFO_H

#include <node.h>
#include "MediaInfo/MediaInfo.h"

class NativeMediaInfo : public node::ObjectWrap {
 public:
  static void Init(v8::Handle<v8::Object> target);

 private:
  NativeMediaInfo();
  ~NativeMediaInfo();

  static v8::Handle<v8::Value> New(const v8::Arguments& args);
  static v8::Handle<v8::Value> Feed(const v8::Arguments& args);

  MediaInfoLib::MediaInfo *medinfo;
};

#endif
