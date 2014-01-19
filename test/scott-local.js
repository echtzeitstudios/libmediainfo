var medi = require("../lib/index");
var fs = require("fs");

var med = new medi({});

var vid = fs.createReadStream("/Users/scott/ex.mp4");
vid.on("open", function(){ 
  var foo = fs.createWriteStream("/dev/null");
  
  foo.on("open", function() {
    console.log("starting");
    vid.pipe(med).pipe(foo);
  });

});

med.on("finished", function(retobj) {
  console.dir(retobj, { depth: null });
  process.exit(0);
});


