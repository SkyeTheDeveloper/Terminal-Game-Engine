#include "CCT.h"

const char player = '@';
char map[7][7];
int position[2];
int world_number = 0;
bool active = true;

void initialize() {
    memcpy(map, map0, sizeof(map));
    position[0] = 3;
    position[1] = 3;
    map[position[1]][position[0]] = player;
    game_loop();
}

void game_loop() {
    char input;
    while (active) {
        render_map();
        scanf(" %c", &input);
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
            case 'e':
                next_map();
                break;
        }
    }
}

void render_map() {
    clear();
    for (int i = 0; i < length(map); i++) {
        for (int j = 0; j < length(map[i]); j++) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}

void movement(int delta_x, int delta_y) {
    int x = position[0];
    int y = position[1];
    int target_x = x + delta_x;
    int target_y = y + delta_y;
    char target_tile = map[target_y][target_x];
    if (target_tile == ' ') {
        map[y][x] = ' ';
        position[0] += delta_x;
        position[1] += delta_y;
        map[target_y][target_x] = player;
    }
}

void next_map() {
    world_number++;
    switch (world_number) {
        case 1:
            disp("You win!", false);
            active = false;
            break;
    }
}