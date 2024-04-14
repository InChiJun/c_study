// 출처: 백준 https://www.acmicpc.net/problem/2606     https://tre2man.tistory.com/132

#include <stdio.h>
#include <stdlib.h>

int pc[100][100] = {0};
int visited[100] = {0};
int virus;

void dfs(int start, int num){
    visited[start] = 1;

    // for(int i = 1;)
}

int main (void){
    int com, network;
    int h, w;
    
    scanf("%d", &com);
    scanf("%d", &network);

    for(int i=0; i < network; i++){
        scanf("%d %d", &h, &w);
        pc[h][w] = 1;
        pc[w][h] = 1;
        
    }
    dfs(0, network);
    
    printf("%d\n", virus);
}