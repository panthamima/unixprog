#include "../libc.h"


#define BUFSIZE 4096

int main(void) {
    int n;
    char buf[BUFSIZE];
    
    while((n = read(STDIN_FILENO, buf, BUFSIZE)) > 0) {
        if(write(STDOUT_FILENO, buf, n) != n) {
            printf("error write\n");
            exit(1);
        }
    }
    if(n < 0) {
        printf("error read\n");
        exit(1);    
    }
    return 0;
}