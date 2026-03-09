/* MainMenu.c
 * Author(s): Skylar Koningin
 * Description: Serves as the entry point and Main Menu for the game
 * Indetation Style: Allman
 */

#include "SkyesUtils.hpp"
#include "miniaudio.hpp"
#include "sounds/Sounds.h"
#include "MainMenu.hpp"
#include "Game.hpp"
#include <iostream>
#include <vector>

struct MenuData
{
    std::vector<std::string> menu_options = 
    {
        "Start Game",
        "Settings", 
        "Credits", 
        "Exit Game"
    };
    int menu_index;
    bool menu_active;
};

#ifdef _WIN32
    UINT def_cp;
#endif
struct MenuData md;

void display_menu(void);
void handle_input(int selection);
void game_start(void);
void settings(void);
void credits(void);
void exit_game(void);


int main(void)
{
    #ifdef _WIN32
        def_cp = GetConsoleOutputCP();
        SetConsoleOutputCP(CP_UTF8);
    #endif
    
    audio_setup();
    
    main_menu();
    
    return 0;
}


void main_menu(void)
{
    md.menu_index = 0;
    md.menu_active = true;
    
    printf("\e[?25l");
    
    char input;
    while (md.menu_active)
    {
        display_menu();
        
        input = getch();
        switch (input)
        {
            case 'w':
                md.menu_index--;
                if (md.menu_index < 0)
                {
                    md.menu_index = 0;
                }
                else 
                {
                    sound("button", button_mp3, button_len);
                }
                break;
            case 's':
                md.menu_index++;
                if (md.menu_index > md.menu_options.size() - 1)
                {
                    md.menu_index = md.menu_options.size() - 1;
                }
                else 
                {
                    sound("button", button_mp3, button_len);
                }
                break;
            case 10:
            case 13:
                md.menu_active = false;
                sound("select", select_mp3, select_len);
                eep(0.15);
                handle_input(md.menu_index);
                break;
        }
    }
}


void display_menu(void)
{
    clear();
    
    printf("   █████████\n  ███░░░░░███\n ███     ░░░   ██████   █████████████    ██████\n░███          ░░░░░███ ░░███░░███░░███  ███░░███\n░███    █████  ███████  ░███ ░███ ░███ ░███████\n░░███  ░░███  ███░░███  ░███ ░███ ░███ ░███░░░\n ░░█████████ ░░████████ █████░███ █████░░██████\n  ░░░░░░░░░   ░░░░░░░░ ░░░░░ ░░░ ░░░░░  ░░░░░░\n");
    
    for (int i = 0; i < md.menu_options.size(); i++)
    {
      if (i == md.menu_index)
      {
          std::cout << "> " << md.menu_options[i] << std::endl;
      }
      else
      {
        std::cout << "  " << md.menu_options[i] << std::endl;
      }
    }
}


void handle_input(int selection)
{
    switch (selection)
    {
        case 0:
            initialize();
            break;
        case 1:
            settings();
            break;
        case 2:
            credits();
            break;
        case 3:
            exit_game();
            break;
    }
}

void settings(void)
{
    disp("There are no settings right now", false);
    eep(1);
    md.menu_active = true;
}


void credits(void)
{
    clear();
    disp("Lead Developer:\nSkylar Koningin (github.com/SkyeTheDeveloper)\n\nAudio Files:\nPixabay (pixabay.com)\n\nAudio Playback (via miniaudio):\nDavid Reid (github.com/mackron/miniaudio)\n\nMap Generation:\nASCII Art Archive (asciiart.eu)\n\n\n", false);
    eep(3);
    disp("Thanks for using our code!", false);
    eep(3);
    md.menu_index = 0;
    md.menu_active = true;
}


void exit_game(void)
{
    disp("Thanks for playing!", false);
    eep(1);
    std::cout.flush() << "\e[?25h";
    
    #ifdef _WIN32
        SetConsoleOutputCP(def_cp);
    #endif
}