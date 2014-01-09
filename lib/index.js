var bind = require('bindings')('binding.node');

var stream = require('stream');
var util = require('util');
util.inherits(MediaInfo, stream.PassThrough);

function MediaInfo (options) {
  var self = this;

  if(!(self instanceof MediaInfo)){
    return new MediaInfo(options);
  }

  self.mi_handle = new bind.NativeMediaInfo(options);
  stream.PassThrough.call(self, options);

  return self;
}

MediaInfo.prototype._transform = function(chunk, enc, cb) {
  var self = this;
  var retobj = self.mi_handle.feed(chunk);
  if(retobj !== undefined) {
    self.emit("finished", retobj);
  }
  cb(null, chunk);
}

module.exports = MediaInfo;
