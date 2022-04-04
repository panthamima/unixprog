#include "../libc.h"

int main(void) {
    printf("user_id - %d | group_id - %d\n", getuid(), getgid());
    return 0;
}