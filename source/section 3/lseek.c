#include "../libc.h"


// ./a.out < "directory name"
int main(void) {
    if(lseek(STDIN_FILENO, 0, SEEK_CUR) == -1) {
        error("cant seek");
    }
    else {
        printf("the move is completed\n");
    }
    return 0;
}