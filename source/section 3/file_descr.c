#include "../libc.h"

int main(int argc, char* argv[]) {
    int val;

    if(argc != 2) {
        error("use: ./a.out <descriptor number>");
    }

    if((val = fcntl(atoi(argv[1]), F_GETFL, 0)) < 0) {
        printf("error fcntl for descriptor: %d", atoi(argv[1]));
    }

    switch (val & O_ACCMODE) {
        case O_RDONLY:
            printf("only read\n");
            break;
        case O_WRONLY:
            printf("only write\n");
        default: 
            error("unknown mode\n");
    }
    #if !defined(_POSIX_C_SOURSE) && defined(O_FSYNC) && (O_FSYNC != O_SYNC)
        if(val && O_FSYNC)
            printf(", synchronous mode\n");
    #endif
    putchar('\n');
    return 0;

}


