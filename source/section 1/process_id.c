#include "../libc.h"

int main(void) {
    printf("process have id: [%d]\n", (long)getpid());
    return 0;
}