#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    const char* park[] = {"SOO","OOO","OOO","OOO"};
    if(park[0][0] == 'S'){
        printf("Find success!\n");
    }

    char* routes[] = {"E 2","S 2","W 1"};
    char* direct;
    int num = 0;

    direct = strtok(routes[0], " ");
    num = strtok(NULL, " ");

    printf("%s, %d\n", direct, num);

    return 1;
}


