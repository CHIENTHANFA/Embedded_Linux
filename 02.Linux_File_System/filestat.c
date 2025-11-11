#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include <string.h>

void show_usage(const char *prog_name) {
    fprintf(stderr, "Usage: %s <file_path>\n", prog_name);
}

const char* get_file_type(mode_t mode) {
    if (S_ISREG(mode)) return "Regular File";
    if (S_ISDIR(mode)) return "Directory";
    if (S_ISLNK(mode)) return "Symbolic Link";
    return "Other";
}

void print_mod_time(time_t mod_time) {
    char buf[64];
    struct tm *info = localtime(&mod_time);
    if (info) {
        strftime(buf, sizeof(buf), "%d-%m-%Y %H:%M:%S", info);
        printf("Last Modified  : %s\n", buf);
    } else {
        printf("Last Modified  : (unknown)\n");
    }
}

int main(int argc, char *argv[]) {

    if (argc != 2) {
        show_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *path = argv[1];
    struct stat info;

    
    if (lstat(path, &info) == -1) {
        perror("Error getting file info");
        return EXIT_FAILURE;
    }

    
    printf("========== File Metadata ==========\n");
    printf("File Path      : %s\n", path);
    printf("File Type      : %s\n", get_file_type(info.st_mode));
    printf("Size           : %lld bytes\n", (long long)info.st_size);
    print_mod_time(info.st_mtime);
    printf("===================================\n");

    return EXIT_SUCCESS;
}
