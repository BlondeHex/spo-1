#include "second_mode.h";

int second_mode(char *filePath) {
    FileSystem *fileSystem = openFileSystem(filePath);
    if (fileSystem != NULL) {
        int exitFlag = 0;
        char *inputString = malloc(1024);
        while (!exitFlag) {
            printf("> ");
            fgets(inputString, 1024, stdin);
            char *command = strtok(inputString, " \n");
            if (command == NULL) {
                continue;
            }
            char *path = strtok(NULL, " \n");
            char *outPath = strtok(NULL, " \n");
    

            if (strcmp(command, "exit") == 0) {
                exitFlag = 1;
            } else if (strcmp(command, "help") == 0) {
                help();
            } else if (strcmp(command, "ls") == 0) {
                ls(fileSystem, path);
            } else if (strcmp(command, "pwd") == 0) {
                pwd(fileSystem);
            } else if (strcmp(command, "cd") == 0) {
                cd(fileSystem, path);
            } else if (strcmp(command, "cp") == 0) {
                cp(fileSystem, path, outPath);
            } else {
                printf("Wrong command. Enter 'help' to get help.\n");
            }
        }
        closeFileSystem(fileSystem);
        return 0;
    }
    printf("Invalid path\n");
    return -1;
}