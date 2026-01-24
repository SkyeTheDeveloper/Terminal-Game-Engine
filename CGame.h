#ifndef CGame
#define CGame

#define length(arr) sizeof(arr) / sizeof(arr[0])

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#ifdef _WIN32
    #include <conio.h>
    #include <windows.h>
    #define eep(s) Sleep((DWORD)((s) * 1000))
#else
    #include <termios.h>
    #include <unistd.h>
    #define eep(s) usleep((useconds_t)((s) * 1000000))
    int getch();
#endif

void disp(char text[], bool question);
void progress_bar(int length);
void clear();

void main_menu();

void initialize();

extern char map0[7][7];

#endif