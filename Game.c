/* Game.c
 * Author(s): Skylar Koningin
 * Description: Provides the basic game logic
 */

#include "SkyesUtils.h"
#include "Map.h"

struct WorldData {
    char player;
    char t_floor;
    char map[7][7];
    int position[2];
    int score;
    int world_number;
    bool active;
};

struct WorldData wd;

void game_loop(void);
void render_map(void);
void movement(int delta_x, int delta_y);
void next_map(void);
    
void initialize(void) {
    wd.player  = '@';
    wd.t_floor = ' ';
    wd.world_number = 0;
    wd.score++;
    memcpy(wd.map, map0, sizeof(wd.map));
    wd.position[0] = 1;
    wd.position[1] = 1;
    wd.map[wd.position[1]][wd.position[0]] = wd.player;
    wd.active = true;
    
    game_loop();
}

void game_loop(void) {
    char input;
    while (wd.active) {
        render_map();
        input = getch();
        switch (input) {
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

void render_map(void) {
    clear();
    for (int i = 0; i < length(wd.map); i++) {
        for (int j = 0; j < length(wd.map[i]); j++) {
            printf("%c ", wd.map[i][j]);
        }
        printf("\n");
    }
    printf("(%d,%d)\n", wd.position[0], wd.position[1]);
    printf("%d\n", wd.score);
}

void movement(int delta_x, int delta_y) {
    int x = wd.position[0];
    int y = wd.position[1];
    int target_x = x + delta_x;
    int target_y = y + delta_y;
    char target_tile = wd.map[target_y][target_x];
    
    if (target_tile == '.' || target_tile == wd.t_floor || target_tile == '*') {
        wd.map[y][x] = ' ';
        
        if (target_tile == '.') {
            wd.score++;
        }
        
        wd.position[0] += delta_x;
        wd.position[1] += delta_y;
        wd.map[target_y][target_x] = wd.player;
        
        if (target_tile == '*') {
            next_map();
        }
    }
}

void next_map(void) {
    render_map();
    
    wd.world_number++;
    switch (wd.world_number) {
        case 1:
            disp("You win!", false);
            wd.active = false;
            printf("\e[?25h");
            break;
        default:
            initialize();
            break;
    }
}