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
void display_menu();
void handle_input(int selection);
void settings();
void credits();
void exit_game();

void initialize();
void game_loop();
void render_map();
void movement(int delta_x, int delta_y);
void next_map();

extern char map0[7][7];

#endif