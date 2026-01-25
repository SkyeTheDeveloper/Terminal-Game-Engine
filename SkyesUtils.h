/* SkyesUtils.h
 * Author(s): Skylar Koningin
 * Description: Provides access to all of the functions
 */

#ifndef SKYES_UTILS
#define SKYES_UTILS

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define length(arr) sizeof(arr) / sizeof(arr[0])
#ifdef _WIN32
    #include <conio.h>
    #include <windows.h>
    
    #define eep(s) Sleep((DWORD)((s) * 1000))
#else
    #include <termios.h>
    #include <unistd.h>
    
    #define eep(s) usleep((useconds_t)((s) * 1000000))
    
    int getch(void);
#endif

void disp(char text[], bool question);
void progress_bar(int length);
void clear(void);

#endif