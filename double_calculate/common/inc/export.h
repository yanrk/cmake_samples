#ifndef COMMON_EXPORT_H
#define COMMON_EXPORT_H

#ifdef _WIN32
    #ifdef EXPORT_DLL
        #define COMMON_API     __declspec(dllexport)
    #else
        #ifdef IMPORT_DLL
            #define COMMON_API __declspec(dllimport)
        #else
            #define COMMON_API
        #endif
    #endif
#else
    #define COMMON_API         __attribute__((visibility("default")))
#endif

#endif // COMMON_EXPORT_H
