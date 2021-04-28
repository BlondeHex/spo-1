#include "second_mode.h"

void handle_command(char *command, char *path, char *outPath, int *flag, FileSystem *fileSystem){
  if (strcmp(command, "exit") == 0) {
    *flag = 0;
  } else if (strcmp(command, "help") == 0) {
      help();
  } else if (strcmp(command, "cp") == 0) {
      cp(fileSystem, path, outPath);
  } else if (strcmp(command, "ls") == 0) {
      ls(fileSystem, path);
  } else if (strcmp(command, "cd") == 0) {
      cd(fileSystem, path);
  } else if (strcmp(command, "pwd") == 0) {
      pwd(fileSystem);
  } else {
      printf("Invalid command. Enter 'help'\n");
  }
}

int second_mode(char *filePath) {
    FileSystem *fileSystem = openFileSystem(filePath);
    if (fileSystem != NULL) {
        int flag = 1; //to stop work
        char *inputString = malloc(1024);
        while (flag) {
          printf("> ");
          fgets(inputString, 1024, stdin);
          char *command = strtok(inputString, " \n");
          if (command != NULL) {
            char *path = strtok(NULL, " \n");
            char *outPath = strtok(NULL, " \n");
            handle_command(command, path, outPath, &flag, fileSystem);
          }
        }
        closeFileSystem(fileSystem);
        return 0;
    }
    printf("Invalid path\n");
    return -1;
}