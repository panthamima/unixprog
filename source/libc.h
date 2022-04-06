#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <dirent.h>
#include <time.h>
#include <ctype.h>
#include <complex.h>
#include <fenv.h>
#include <assert.h>
#include <float.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h> // 46

#define BUFSIZE 4096
#define MAXLINE 4096

void error(char *error_msg) {
    printf("error: %s\n", error_msg);
    exit(1);
}

void success(char* success_msg) {
    printf("success: %s\n", success_msg);
}