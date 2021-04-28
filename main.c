#include "main.h"
#include "hfsplus_utils.h"


int main(int argc, char **argv) {

    if (argc >= 2 && strcmp(argv[1], "1") == 0) {
        printList();
        return 0;
    }
    if (argc >= 3 && strcmp(argv[1], "2") == 0) {
        shellMode(argv[2]);
        return 0;
    }
    printf("Incorrect arguments\n");
    return 0;
}