#include "second_mode.h"

void handle_command(char *input, int *flag){
  if (strcmp(input, "exit") == 0) {
    *flag = 0;
  } else if (strcmp(input, "help") == 0) {
    help();
  } else if (strcmp(input, "ls") == 0) {
    ls(fileSystem, path);
  } else if (strcmp(input, "pwd") == 0) {
    pwd(fileSystem);
  } else if (strcmp(input, "cd") == 0) {
    cd(fileSystem, path);
  } else if (strcmp(command, "cp") == 0) {
    cp(fileSystem, path, outPath);
  } else {
    printf("Invalid command. Enter 'help'\n");
  }
}

int second_mode(char *filePath) {
    FileSystem *fileSystem = openFileSystem(filePath);
    if (fileSystem != NULL) {
        int flag = 1;
        char *inputString = malloc(1024);
        while (flag) {
            printf("> ");
            fgets(inputString, 1024, stdin);
            char *command = strtok(inputString, " \n");
            if (command == NULL) {
                continue;
            }
            char *path = strtok(NULL, " \n");
            char *outPath = strtok(NULL, " \n");
            handle_command(command, &flag);

            
        }
        closeFileSystem(fileSystem);
        return 0;
    }
    printf("Invalid path\n");
    return -1;
}