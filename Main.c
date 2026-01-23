#include "SkyesUtils.h"
#include "header.h"

char menu_options[4][10];
int menu_index = 0;
bool menu_active = true;

int main() {
    main_menu();
}

void main_menu() {
    char main_options[4][10] = {"Start Game", "Settings", "Credits", "Exit Game"};
    memcpy(menu_options, main_options, sizeof(main_options));
    char input;
    while (menu_active) {
        display_menu();
        scanf("%c", &input);
        switch (input) {
            case 'w':
                menu_index--;
                if (menu_index < 0) {
                    menu_index = 0;
                }
                break;
            case 's':
                menu_index++;
                if (menu_index > 3) {
                    menu_index = 3;
                }
                break;
            case 'e':
                menu_active = false;
                handle_input(menu_index);
                break;
        }
    }
}

void display_menu() {
    clear();
    printf("   █████████\n  ███░░░░░███\n ███     ░░░\n░███\n░███\n░░███     ███\n ░░█████████\n  ░░░░░░░░░\n\n   █████████\n  ███░░░░░███\n ███     ░░░   ██████   █████████████    ██████\n░███          ░░░░░███ ░░███░░███░░███  ███░░███\n░███    █████  ███████  ░███ ░███ ░███ ░███████\n░░███  ░░███  ███░░███  ░███ ░███ ░███ ░███░░░\n ░░█████████ ░░████████ █████░███ █████░░██████\n  ░░░░░░░░░   ░░░░░░░░ ░░░░░ ░░░ ░░░░░  ░░░░░░\n");
    for (int i = 0; i < length(menu_options); i++) {
        char *prefix[2];
        char *suffix[2];
        if (menu_options[i] == menu_options[menu_index]) {
            *prefix = "> ";
            *suffix = " <";
        }
        printf(*prefix, menu_options[i], suffix);
    }
}

void handle_input(int selection) {
    switch (selection) {
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

void settings() {
    disp("There are no settings right now", false);
    main_menu();
}

void credits() {
    disp("There are no credits right now", false);
    main_menu();
}

void exit_game() {
    disp("Thanks for playing!", false);
}