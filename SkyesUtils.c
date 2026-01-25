#include "CGame.h"

#ifndef _WIN32
    int getch(void) {
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

void disp(char text[], bool question) {
    int length = strlen(text);
    for (int i = 0; i < length; i++) {
        printf("%c", text[i]);
        fflush(stdout);
        eep(0.05);
    }
    if (!question)
    {
        printf("\n");
    }
}

void progress_bar(int length) {
    printf("<");
    fflush(stdout);
    eep(0.05);
    for (int i = 0; i < length - 2; i++) {
        printf("#");
        fflush(stdout);
        eep(0.05);
    }
    printf(">\n");
    eep(2);
}

void clear(void) {
    printf("\033[H\033[2J");
    fflush(stdout);
}