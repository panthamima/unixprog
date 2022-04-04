#include "../libc.h"

int main() {
    int c;

    while((c = getc(stdin)) != EOF) {
        if(putc(c, stdout) == EOF) {
            error("error stdout");
        }
    }
    if(ferror(stdin)) {
        error("error stdin");
    }
    return 0;
}