{
  "targets": [
    {
      "target_name": "binding",
      'include_dirs': [ 'deps/mediainfo', 'deps/zenlib' ],
      'dependencies': [
        'deps/mediainfo/libmediainfo.gyp:libmediainfo',
      ],
      "sources": [ "src/binding.cc" ]
    }
  ]
}
