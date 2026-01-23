#include "SkyesUtils.h"
#include <stdio.h>

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

void clear() {
    printf("\033[H\033[2J");
    fflush(stdout);
}