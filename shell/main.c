#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GOON_RL_BUFSIZE 1024

char *goon_read_line(void) {
    int bufsize = GOON_RL_BUFSIZE;
    int position = 0;
    char *buffer = malloc(sizeof(char) * bufsize); // alloc buffer
    int c;

    if(!buffer) { // failed to allocate maybe
        fprintf(stderr, "goon: allocation error\n");
        exit(EXIT_FAILURE);
    }

    while(1) {
        c = getchar(); // get the char

        if(c == EOF || c == '\n') { // if eof
            buffer[position] = '\0'; // change with null terminator
            return buffer;
        } else {
            buffer[position] = c; // c is an int, why?
        }
        position++;

        if(position >= bufsize) {
            bufsize += GOON_RL_BUFSIZE;
            buffer = realloc(buffer, bufsize);

            if(!buffer) {
                fprintf(stderr, "goon: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
    }
}

#define GOON_TOK_BUFSIZE 64
#define GOON_TOK_DELIM " \t\r\n\a"

char **goon_split_line(char *line) {
    int bufsize = GOON_TOK_BUFSIZE , position = 0;
    char **tokens = malloc(bufsize * sizeof(char*));
    char *token;
    
    if(!tokens) {
        fprintf(stderr, "goon: allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, GOON_TOK_DELIM);
    while(!token) {
        tokens[position] = token;
        position++;

        if(position >= bufsize) {
            bufsize += GOON_TOK_BUFSIZE;
            tokens = malloc(bufsize * sizeof(char*));
            if(!tokens) {
                fprintf(stderr, "goon: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, GOON_TOK_DELIM);
    }

    tokens[position] = NULL; 
    return tokens;
}

int goon_execute(void) {

    return -1;
}

void goon_loop(void) {
    char *line;
    char **args;
    int status;

    do {
        printf("> ");
        line = goon_read_line();
        args = goon_split_line(line);
        status = goon_execute();
        free(line);
        free(args);
    }while(status);
}

int main(int argc, char **argv) {
    goon_loop();

    return EXIT_SUCCESS;
}
