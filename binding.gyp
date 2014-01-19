{
  "targets": [
    {
      "target_name": "binding",
      'include_dirs': [ 
        'deps/mediainfo', 
        'deps/mediainfo/ThirdParty/tinyxml2',
        'deps/mediainfo/ThirdParty/base64',
        'deps/mediainfo/ThirdParty/md5',
        'deps/zenlib',
        "<!(node -e \"require('nan')\")",
        "src"
      ],
      'defines': [
        'STDC_HEADERS=1', 
        'HAVE_SYS_TYPES_H=1', 
        'HAVE_SYS_STAT_H=1', 
        'HAVE_STDLIB_H=1', 
        'HAVE_STRING_H=1', 
        'HAVE_MEMORY_H=1', 
        'HAVE_STRINGS_H=1', 
        'HAVE_INTTYPES_H=1', 
        'HAVE_STDINT_H=1', 
        'HAVE_UNISTD_H=1', 
        'HAVE_DLFCN_H=1', 
        'HAVE_ZLIB_H=1', 
        'UNICODE', 
        'SIZE_T_IS_LONG', 
        'MEDIAINFO_LIBCURL_NO', 
        'MEDIAINFO_LIBMMS_NO',
        'MEDIAINFO_DEMUX_YES=1',
        'MEDIAINFO_EVENTS_YES=1' 
        'MEDIAINFO_MINIMIZESIZE=1', 
        'MEDIAINFO_MINIMAL_YES=1', 
        'MEDIAINFO_DVDIF_ANALYZE_YES=1',
        'MEDIAINFO_NEXTPACKET_YES=1'
      ],
      'dependencies': [
        'deps/zenlib/libzen.gyp:libzen',
        'deps/mediainfo/libmediainfo.gyp:libmediainfo'
      ],
      'cflags_cc': [ '-g -O2 -fPIC' ],
      "sources": [ "src/binding.cc", "src/mediainfo.cc" ],
    }
  ]
}
