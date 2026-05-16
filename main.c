#include "todo.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: todo <args>. Exiting 1.");
        exit(1);
    }

    i8 test = 5;
    printf("Test: %d\n", test);
    return 0;
}
