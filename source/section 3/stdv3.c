#include "../libc.h"

int main(void) {
    int  n;
    char buf[BUFSIZE];
    while((n = read(STDIN_FILENO, buf, BUFSIZE)) > 0) {
        if(write(STDOUT_FILENO, buf, n) != n) {
            error("write");
        }
    }
    if(n < 0) {
        error("read");
    }
    return 0;
}