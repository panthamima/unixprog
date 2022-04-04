#include "../libc.h"

int main(void) {
    char buf[BUFSIZE];
    pid_t pid;
    int status;

    printf("%%");

    while(fgets(buf, MAXLINE, stdin) != NULL) {
        if(buf[strlen(buf) - 1] == '\n') {
            buf[strlen(buf) - 1] = 0;
        }
        if((pid = fork()) < 0) {
            error("error request fork");
        }
        else if(pid == 0) {
            execlp(buf, buf, (char*)0);
            exit(127);
        }
        // parent process
        if((pid = waitpid(pid, &status, 0)) < 0) {
            error("error request waitpid");
        }
        printf("%%");
    }
    return 0;
}