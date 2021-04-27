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

int str_starts_with(char* src, char* substr) {
    if (strncmp(src, substr, strlen(substr)) == 0) {
        return 1;
    } else {
        return 0;
    }
}

int printList() {
    DIR *device_dir;
    DIR *section_dir;
    struct dirent *device_dir_entry;
    struct dirent *section_dir_entry;
    char section_path[100] = {'\0'};

    device_dir = opendir(SYSTEM_DIR);
    if (device_dir) {
        while ((device_dir_entry = readdir(device_dir)) != NULL) {
            if (str_starts_with(device_dir_entry->d_name, "sd")) {
                printf("device - %s\n", device_dir_entry->d_name);
                strcpy(section_path, SYSTEM_DIR);
                strcat(section_path, device_dir_entry->d_name);
                section_dir = opendir(section_path);
                if (section_dir) {
                    while ((section_dir_entry = readdir(section_dir)) != NULL) {
                       if (str_starts_with(section_dir_entry->d_name, "sd")) {
                           printf("section - %s\n", section_dir_entry->d_name);}
                    }
                }
            }
        }
        closedir(device_dir);
        return 0;
    }
    return -1;
}

int shellMode(char *filePath) {
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
