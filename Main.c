#include "CGame.h"

struct MenuData {
    char *menu_options[4];
    int menu_index;
    bool menu_active;
};

#ifdef _WIN32
    UINT def_cp;
#endif
struct MenuData md;

void display_menu(void);
void handle_input(int selection);
void settings(void);
void credits(void);
void exit_game(void);

int main(void) {
    #ifdef _WIN32
        def_cp = GetConsoleOutputCP();
        SetConsoleOutputCP(CP_UTF8);
    #endif
    md.menu_index = 0;
    md.menu_active = true;
    main_menu();
    return 0;
}

void main_menu(void) {
    printf("\e[?25l");
    char *main_options[4] = {"Start Game", "Settings", "Credits", "Exit Game"};
    memcpy(md.menu_options, main_options, sizeof(md.menu_options));
    char input;
    while (md.menu_active) {
        display_menu();
        input = getch();
        switch (input) {
            case 'w':
                md.menu_index--;
                if (md.menu_index < 0) {
                    md.menu_index = 0;
                }
                break;
            case 's':
                md.menu_index++;
                if (md.menu_index > 3) {
                    md.menu_index = 3;
                }
                break;
            case 10:
            case 13:
                md.menu_active = false;
                handle_input(md.menu_index);
                break;
        }
    }
}

void display_menu(void) {
    clear();
    printf("   █████████\n  ███░░░░░███\n ███     ░░░\n░███\n░███\n░░███     ███\n ░░█████████\n  ░░░░░░░░░\n\n   █████████\n  ███░░░░░███\n ███     ░░░   ██████   █████████████    ██████\n░███          ░░░░░███ ░░███░░███░░███  ███░░███\n░███    █████  ███████  ░███ ░███ ░███ ░███████\n░░███  ░░███  ███░░███  ░███ ░███ ░███ ░███░░░\n ░░█████████ ░░████████ █████░███ █████░░██████\n  ░░░░░░░░░   ░░░░░░░░ ░░░░░ ░░░ ░░░░░  ░░░░░░\n");
    for (int i = 0; i < length(md.menu_options); i++) {
      if (i == md.menu_index) {
        printf("> %s <\n", md.menu_options[i]);
      } else {
        printf("%s\n", md.menu_options[i]);
      }
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

void settings(void) {
    disp("There are no settings right now", false);
}

void credits(void) {
    disp("There are no credits right now", false);
}

void exit_game(void) {
    disp("Thanks for playing!", false);
    printf("\e[?25h");
    #ifdef _WIN32
        SetConsoleOutputCP(def_cp);
    #endif
}