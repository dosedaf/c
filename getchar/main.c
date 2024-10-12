#include <stdio.h>

int main(int argc, char **argv) {
    int position;
    int c = getchar();

    if(c == EOF || c == '\n') {
        printf("eof");
    } else {
        printf("char: %d", c);
    }

    return 0;
}
