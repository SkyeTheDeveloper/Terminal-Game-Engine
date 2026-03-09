/* Game.c
 * Author(s): Skylar Koningin
 * Description: Provides the basic game logic
 * Indetation Style: Allman
 */

#include "MainMenu.hpp"
#include "SkyesUtils.hpp"
#include "sounds/Sounds.h"
#include "Map.hpp"
#include <iostream>
#include <vector>

struct WorldData
{
    char player = '@';
    char t_floor = ' ';
    std::vector<std::vector<char>> map;
    int position[2];
    int score = 0;
    int world_number = 0;
    bool active;
};

struct WorldData wd;

void game_loop(void);
void render_map(void);
void movement(int delta_x, int delta_y);
void next_map(void);

void initialize(void)
{
    progress_bar(22);
    
    wd.score++;
    if (wd.world_number == 0) {
        wd.map = map0;
    } else if (wd.world_number == 1) {
        wd.map = map1;
    } else if (wd.world_number == 2) {
        wd.map = map2;
    } else if (wd.world_number == 3) {
        wd.map = map3;
    } else if (wd.world_number == 4) {
        wd.map = map4;
    }
    wd.position[0] = 1;
    wd.position[1] = 1;
    wd.map[wd.position[1]][wd.position[0]] = wd.player;
    wd.active = true;
    
    game_loop();
}

void game_loop(void)
{
    char input;
    while (wd.active)
    {
        render_map();
        input = getch();
        switch (input)
        {
            case 'w':
                movement(0, -1);
                break;
            case 's':
                movement(0, 1);
                break;
            case 'a':
                movement(-1, 0);
                break;
            case 'd':
                movement(1, 0);
                break;
        }
    }
}

void render_map(void)
{
    clear();
    for (int i = 0; i < wd.map.size(); i++)
    {
        for (int j = 0; j < wd.map[i].size(); j++)
        {
            std::cout << wd.map[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "(" << wd.position[0] << "," << wd.position[1] << ")" << std::endl;
    std::cout <<  wd.score << std::endl;
}

void movement(int delta_x, int delta_y)
{
    int x = wd.position[0];
    int y = wd.position[1];
    int target_x = x + delta_x;
    int target_y = y + delta_y;
    char target_tile = wd.map[target_y][target_x];
    
    if (target_tile == '.' || target_tile == wd.t_floor || target_tile == '*')
    {
        wd.map[y][x] = ' ';
        
        sound("movement", movement_mp3, movement_len);
        
        if (target_tile == '.')
        {
            wd.score++;
        }
        
        wd.position[0] += delta_x;
        wd.position[1] += delta_y;
        wd.map[target_y][target_x] = wd.player;
        
        if (target_tile == '*')
        {
            next_map();
        }
    }
}

void next_map(void)
{
    render_map();
    
    wd.world_number++;
    switch (wd.world_number)
    {
        case 5: // only defined as it is since there is no good way to get the total map count
            disp("You win!", false);
            wd.active = false;
            
            eep(1);
            
            progress_bar(22);
            main_menu();
            break;
        default:
            initialize();
            break;
    }
}