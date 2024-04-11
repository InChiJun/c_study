#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    const char* park[] = {"SOO","OOO","OOO","OOO"};
    if(park[0][0] == 'S'){
        printf("Find success!\n");
    }

    char routes[3][3] = {"E 2","S 2","W 1"};
    char direct = routes[0][0];
    int num = atoi(&routes[0][2]);

    int* answer = (int*)malloc(sizeof(int) * 2);

    answer[0] = 0;
    answer[1] = 0;

    printf("%d, %d\n", answer[0], answer[1]);

    return 1;
}


