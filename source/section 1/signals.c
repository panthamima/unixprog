#include "../libc.h"

void sig_int(int signo) {
    printf("%%aborted");
}

int main(void) {
    char buf[MAXLINE];
    pid_t pid;
    int status;

    if(signal(SIGINT, sig_int) == SIG_ERR) {
        error("request signal");
        exit(1);
    }
    printf("%% ");
    while(fgets(buf, MAXLINE, stdin) != NULL) {
        if(buf[strlen(buf) - 1] == '\n') {
            buf[strlen(buf) - 1] = 0;
        }
        if((pid = fork()) < 0) {
            error("request fork");
        }
        else if(pid == 0) {
            execlp(buf, buf, (char*)0);
            printf("error cant request: %s\n", buf);
            exit(1);
        }
        if((pid = waitpid(pid, &status, 0)) < 0) {
            error("request waitpid");
        }
        printf("%% ");
    }
    return 0;
}