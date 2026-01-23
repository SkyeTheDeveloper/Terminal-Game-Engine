#ifndef SkyesUtils
#define SkyesUtils

#ifdef _WIN32
    #include <windows.h>
    #define eep(s) Sleep((DWORD)((s) * 1000))
#else
    #include <unistd.h>
    #define eep(s) usleep((useconds_t)((s) * 1000000))
#endif
#define length(arr) sizeof(arr) / sizeof(arr[0])

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void disp(char text[], bool question);
void progress_bar(int length);
void clear();

#endif