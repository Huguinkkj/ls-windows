#include <stdio.h>
#include <dirent.h>

int main() {
    DIR *directory;
    struct dirent *entry;
    directory = opendir(".");

    if (directory == NULL) {
        printf("Error while opening dir. \n");
        return 1;
    }
    while ((entry = readdir(directory)) != NULL) {
        if (entry->d_type == DT_REG) {
            printf("|_%s\n", entry->d_name);
        } else if (entry->d_type == DT_DIR) {
            printf("|_[+]%s\n", entry->d_name);
        }
    }

    if (closedir(directory) == -1) {
        printf("Error closing directory");
        return 1;
    }

    return 0;
}