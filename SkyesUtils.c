/* SkyesUtils.c
 * Author(s): Skylar Koningin
 * Description: A small, custom-coded library of my most common functions
 * Indetation Style: Allman
 */

#include "SkyesUtils.h"
#include "sounds/Sounds.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#ifndef _WIN32
    
    int getch(void)
    {
        struct termios oldt, newt;
        int ch;
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        ch = getchar();
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        return ch;
    }
#endif

void disp(char *text, bool question)
{
    int length = strlen(text);
    for (int i = 0; i < length; i++)
    {
        sound("text", text_mp3, text_len);
        printf("%c", text[i]);
        fflush(stdout);
        eep(0.05);
    }
    if (!question)
    {
        printf("\n");
    }
}

void progress_bar(int length)
{
    clear();
    printf("<");
    fflush(stdout);
    eep(0.05);
    for (int i = 0; i < length - 2; i++)
    {
        printf("#");
        fflush(stdout);
        eep(0.05);
    }
    printf(">\n");
    eep(2);
}

void clear(void)
{
    printf("\033[H\033[2J");
    fflush(stdout);
}

void sound(const char* sound_name, unsigned char* sound_file, unsigned int size)
{
    ma_resource_manager_register_encoded_data(
        ma_engine_get_resource_manager(&engine), 
        sound_name, 
        sound_file, 
        size
    );
    ma_engine_play_sound(&engine, sound_name, NULL);
}