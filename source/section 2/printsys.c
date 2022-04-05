#include "../libc.h"

static void pr_sysconf(char*, int);
static void pr_pathconf(char*, char*, int);

int main(int argc, char* argv[]) {
    if(argc != 2) {
        error("use: ./a.out <directory>");
    }
    #ifdef ARG_MAX
        printf("ARG_MAX declarated as: %d\n", ARG_MAX+0);
    #else   
        printf("ARG_MAX not found\n");
    #endif

    #ifdef _SC_ARG_MAX
        printf("_SC_ARG_MAX declarated as: %d\n", _SC_ARG_MAX+0);
    #else
        printf("_SC_ARG_MAX not found\n");
    #endif

    #ifdef MAX_CANON
        printf("MAX_CANON declarated as: %d\n", MAX_CANON+0);
    #else
        printf("MAX_CANON not found\n");
    #endif

    #ifdef _PC_MAX_CANON
        pr_pathconf("_PC_MAX_CANON =", argv[1], _PC_MAX_CANON);
    #else
        printf("_PC_MAX_CANON not found\n");
    #endif

    return 0;
}

static void pr_sysconf(char* msg, int name) {
    long val;

    fputs(msg, stdout);
    errno = 0;

    if((val = sysconf(name)) < 0) {
        if(errno != 0) {
            if(errno == EINVAL) {
                fputs("(not support)\n", stdout);
            }
            else {
                error("request sysconf");
            }
        }
        else {
            fputs("(no restrictions)\n", stdout);
        }
    }
    else {
        printf("%ld\n", val);
    }
}

static void pr_pathconf(char* msg, char* path, int name) {
    long val;

    fputs(msg, stdout);
    errno = 0;

    if((val = pathconf(path, name)) < 0) {
        if(errno != 0) {
            if(errno == EINVAL) {
                fputs("(not support)\n", stdout);
            }
            else {
                printf("error request pathconf path = %s\n", path);
            }
        }
        else {
            fputs("(no restrictions)\n", stdout);
        }
    }
    else {
        printf("%ld\n", val);
    }
}