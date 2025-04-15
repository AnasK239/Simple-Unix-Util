#include <unistd.h>
#include <limits.h>
#include <stdio.h>

int main() {

        char path[PATH_MAX];
        if(getcwd(path,sizeof(path)) == NULL)
        {
                printf("Couldn't Find Directory");
                return -1;
        }

        printf("%s\n",path);

        return 0;
}

