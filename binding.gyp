{

  "targets": [
    {
      "target_name": "binding",
      'include_dirs': [ 
        'deps/mediainfo', 
        'deps/mediainfo/Video',
        'deps/mediainfo/ThirdParty/tinyxml',
        'deps/mediainfo/ThirdParty/base64',
        'deps/mediainfo/ThirdParty/md5',
        'deps/mediainfo/Text',
        'deps/mediainfo/Tag',
        'deps/mediainfo/Multiple',
        'deps/mediainfo/Reader',
        'deps/mediainfo/Image',
        'deps/mediainfo/Export',
        'deps/mediainfo/Duplicate',
        'deps/mediainfo/Audio',
        'deps/mediainfo/Archive',
        'deps/zenlib',
        'deps/zenlib/Format/Html' 
        'deps/zenlib/Format/Http' 
        'deps/zenlib/HTTP_Client' 
      ],
      'dependencies': [
        'deps/zenlib/libzen.gyp:libzen',
        'deps/mediainfo/libmediainfo.gyp:libmediainfo'
      ],
      "sources": [ "src/binding.cc" ],
      "conditions": [
            ["OS == 'mac'", {
                "xcode_settings": {
                    "GCC_ENABLE_CPP_EXCEPTIONS": "YES",
                    "OTHER_CFLAGS": [
                        "-g",
                        "-mmacosx-version-min=10.7",
                        '-std=c++11',
                        "-stdlib=libc++",
                        "-O3",
                        "-D__STDC_CONSTANT_MACROS",
                        "-D_FILE_OFFSET_BITS=64",
                        "-D_LARGEFILE_SOURCE",
                        "-Wall"
                    ],
                    "OTHER_CPLUSPLUSFLAGS": [
                        "-g",
                        "-mmacosx-version-min=10.7",
                        '-std=c++11',
                        "-stdlib=libc++",
                        "-O3",
                        "-D__STDC_CONSTANT_MACROS",
                        "-D_FILE_OFFSET_BITS=64",
                        "-D_LARGEFILE_SOURCE",
                        "-Wall"
                    ]
                }
            }]
        ]

    }
  ]
}
