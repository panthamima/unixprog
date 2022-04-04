#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <dirent.h>
#include <time.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h> // 46

#define BUFSIZE 4096
#define MAXLINE 4096

void error(char *error_type) {
    printf("error: %s\n", error_type);
    exit(1);
}