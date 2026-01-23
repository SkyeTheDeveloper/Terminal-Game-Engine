#include "lib/SkyesUtils.h"

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