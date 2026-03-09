/* SkyesUtils.c
 * Author(s): Skylar Koningin
 * Description: A small, custom-coded library of my most common functions
 * Indetation Style: Allman
 */

#include "SkyesUtils.hpp"
#include "sounds/Sounds.h"
#include <iostream>

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

void disp(std::string text, bool question)
{
    for (int i = 0; i < text.length(); i++)
    {
        sound("text", text_mp3, text_len);
        std::cout.flush() << text[i];
        eep(0.05);
    }
    if (!question)
    {
        std::cout << "\n";
    }
}

void progress_bar(int length)
{
    clear();
    std::cout.flush() << "<";
    eep(0.05);
    for (int i = 0; i < length - 2; i++)
    {
        std::cout.flush() << "#";
        eep(0.05);
    }
    std::cout << ">\n";
    eep(2);
}

void clear(void)
{
    std::cout.flush() << "\033[H\033[2J";
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