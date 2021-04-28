#include "first_mode.h";

int str_starts_with(char* src, char* substr) {
  if (strncmp(src, substr, strlen(substr)) == 0) {
    return 1;
  } else {
    return 0;
  }
}

int first_mode() {
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
              printf("section - %s\n", section_dir_entry->d_name);
            }
          }
        }
      }
    }
    closedir(device_dir);
    return 0;
  }
  return -1;
}