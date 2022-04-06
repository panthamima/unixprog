#include "../libc.h"

char buf_1[] = "qwertyuiop";
char buf_2[] = "QWERTYUIOP";

int main(void) {
    int fd;
    fd = creat("file.hole", 1);

    if(write(fd, buf_1, 10) != 10) {
        error("write buf_1");
    }
    if(lseek(fd, 16384, SEEK_SET) == -1) {
        error("request lseek");
    }
    if(write(fd, buf_2, 10) != 10) {
        error("write buf_2");
    }

    return 0;
}