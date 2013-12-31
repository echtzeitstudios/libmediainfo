{
  'targets': [
    {
      'target_name': 'libzen',
      'type': 'static_library',
      'include_dirs': [ 
        '.',
        'Format/Html',
        'Format/Http',
        'HTTP_Client'
      ],
      'defines': [
        'PACKAGE_NAME="libzen"',
        'PACKAGE_TARNAME="libzen"',
        'PACKAGE_VERSION="0.4.25"',
        'PACKAGE_STRING="libzen 0.4.25"',
        'PACKAGE_BUGREPORT=""',
        'PACKAGE="libzen"',
        'VERSION="0.4.25"',
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
        'UNICODE',
        '_LARGE_FILES ',
        '_FILE_OFFSET_BITS=64',
        'SIZE_T_IS_LONG'
      ],
      # 'cflags_cc': [ '-g -O2 -arch x86_64 -fPIC -c' ],
      'sources': [
        'Conf.cpp',
        'CriticalSection.cpp',
        'Dir.cpp',
        'File.cpp',
        'FileName.cpp',
        'InfoMap.cpp',
        'int128s.cpp',
        'int128u.cpp',
        'MemoryDebug.cpp',
        'OS_Utils.cpp',
        'Translation.cpp',
        'Thread.cpp',
        'Utils.cpp',
        'Ztring.cpp',
        'ZtringList.cpp',
        'ZtringListList.cpp',
        'ZtringListListF.cpp',
        'Format/Html/Html_Handler.cpp',
        'Format/Html/Html_Request.cpp',
        'Format/Http/Http_Cookies.cpp',
        'Format/Http/Http_Handler.cpp',
        'Format/Http/Http_Request.cpp',
        'Format/Http/Http_Utils.cpp'
      ],
      "conditions": [
            ["OS == 'mac'", {
                "xcode_settings": {
                    "GCC_ENABLE_CPP_EXCEPTIONS": "YES",
                    "OTHER_CFLAGS": [
                        "-g",
                        "-mmacosx-version-min=10.7",
                        "-std=c++11",
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
                        "-std=c++11",
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
    },
  ]
}
