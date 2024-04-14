#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(){
    char* answer = (char*)malloc(sizeof(char) * 10);

    answer = "hello";
    answer = "world!";

    for(int i = 0; i < 3; i++){
        printf("%c\n", answer[i]);
    }

    return 1;
}


