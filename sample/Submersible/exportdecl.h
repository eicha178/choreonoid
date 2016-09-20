#ifndef SUBMERSIBL_SAMPLEPLUGIN_EXPORTDECL_H_INCLUDED
# define SUBMERSIBL_SAMPLEPLUGIN_EXPORTDECL_H_INCLUDED

# if defined _WIN32 || defined __CYGWIN__
#  define SUBMERSIBL_SAMPLEPLUGIN_DLLIMPORT __declspec(dllimport)
#  define SUBMERSIBL_SAMPLEPLUGIN_DLLEXPORT __declspec(dllexport)
#  define SUBMERSIBL_SAMPLEPLUGIN_DLLLOCAL
# else
#  if __GNUC__ >= 4
#   define SUBMERSIBL_SAMPLEPLUGIN_DLLIMPORT __attribute__ ((visibility("default")))
#   define SUBMERSIBL_SAMPLEPLUGIN_DLLEXPORT __attribute__ ((visibility("default")))
#   define SUBMERSIBL_SAMPLEPLUGIN_DLLLOCAL  __attribute__ ((visibility("hidden")))
#  else
#   define SUBMERSIBL_SAMPLEPLUGIN_DLLIMPORT
#   define SUBMERSIBL_SAMPLEPLUGIN_DLLEXPORT
#   define SUBMERSIBL_SAMPLEPLUGIN_DLLLOCAL
#  endif
# endif

#ifdef CnoidSubmersibleSamplePlugin_EXPORTS
#   define SUBMERSIBL_SAMPLEPLUGIN_DLLAPI SUBMERSIBL_SAMPLEPLUGIN_DLLEXPORT
#else
#   define SUBMERSIBL_SAMPLEPLUGIN_DLLAPI SUBMERSIBL_SAMPLEPLUGIN_DLLIMPORT
#endif

#endif

#ifdef CNOID_EXPORT
# undef CNOID_EXPORT
#endif
#define CNOID_EXPORT SUBMERSIBL_SAMPLEPLUGIN_DLLAPI
