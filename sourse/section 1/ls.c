#include "../libc.h"

int main(int argc, char* argv[]) {
    DIR             *dp;
    struct dirent *dirp;
    
    if(argc != 2) {
        printf("error: enter ./ls directory \n");
        return 1;
    }

    if((dp = opendir(argv[1])) == NULL) {
        printf("error\n");  
    }
    while((dirp = readdir(dp)) != NULL) {
        printf("%s\n", dirp->d_name);
    }
    closedir(dp);
    return 0;
}