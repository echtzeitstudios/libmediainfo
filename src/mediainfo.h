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

  static NAN_METHOD(New);
  static NAN_METHOD(Feed);

  MediaInfoLib::MediaInfo *medinfo;
};

#endif
