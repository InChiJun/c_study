// 문제: https://school.programmers.co.kr/learn/courses/30/lessons/172928

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int* solution(const char* park[], size_t park_len, const char* routes[], size_t routes_len) {
    int* answer = (int*)malloc(sizeof(int) * 2);
    int w = strlen(park[0]);

    int found = 0;
    // find start index
    for(int i = 0; i < park_len; i++){
        for(int j = 0; j < w; j++){
            if(park[i][j] == 'S'){
                answer[0] = i;
                answer[1] = j;
                found = 1;
                break;
            }
        }
        if(found == 1){
            break;
        }
    }

    // execute routes
    for(int i = 0; i < routes_len; i++){
        char direct = routes[i][0];
        int num = atoi(&routes[i][2]);
        int xBool = 1;
        
        // E
        if(direct == 'E'){
            if(answer[1] + num > strlen(park[0]) - 1){
                continue;
            }
            for(int j = 1; j < num; j++){
                if(park[answer[0]][answer[1] + j] == 'X'){
                    xBool = 0;
                    break;
                }
            }
            if(xBool == 0){
                continue;
            }
        
            answer[1] = answer[1] + num;
        }
        else if(direct == 'W'){
            if(answer[1] - num < 0){
                continue;
            }
            for(int j = 1; j < num; j++){
                if(park[answer[0]][answer[1] - j] == 'X'){
                    xBool = 0;
                    break;
                }
            }
            if(xBool == 0){
                continue;
            }
            if(park[answer[0]][answer[1] - num] == 'X'){
                continue;
            }
        
            answer[1] = answer[1] - num;
        }
        else if(direct == 'S'){
            if(answer[0] + num > park_len - 1){
                continue;
            }
            for(int j = 1; j < num; j++){
                if(park[answer[0] + j][answer[1]] == 'X'){
                    xBool = 0;
                    break;
                }
            }
            if(xBool == 0){
                continue;
            }
        
            answer[0] = answer[0] + num;
        }
        else if(direct == 'N'){
            if(answer[0] - num < 0){
                continue;
            }
            for(int j = 1; j < num; j++){
                if(park[answer[0] - j][answer[1]] == 'X'){
                    xBool = 0;
                    break;
                }
            }
            if(xBool == 0){
                continue;
            }
        
            answer[0] = answer[0] - num;
        }
    }

    return answer;
}

int main(){
    const char* park[] = {"SOO", "OXX", "OOO"};
    size_t park_len = 3;
    const char* routes[] = {"E 2","S 2","W 1"};
    size_t routes_len = 3;

    int* result = solution(park, park_len, routes, routes_len);

    printf("%d, %d", result[0], result[1]);

    return 1;
}