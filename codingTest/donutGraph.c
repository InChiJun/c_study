#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool stick(bool** nodes, size_t edges_rows, int node){
    for(int i = 0; i < edges_rows; i++){
        if(i == edges_rows && nodes[node][i] == 0) // 마지막까지 가리키는 노드가 없을 때
            return 1;
        else if(nodes[node][i]) // 노드가 다른 노드를 가리키고 있을 때
            stick(nodes, edges_rows, i);
    }
    return -1;
}

// edges_rows는 2차원 배열 edges의 행 길이, edges_cols는 2차원 배열 edges의 열 길이입니다.
int* solution(int** edges, size_t edges_rows, size_t edges_cols) {
    bool** nodes = (bool**)malloc(sizeof(bool*) * edges_rows);
    for(int i = 0; i < edges_rows; i++){
        nodes[i] = (bool*)malloc(sizeof(bool) * 2);    
    }
    
    int* answer[4] = {0};
    
    for(int i = 0; i < edges_rows; i++){ // node 채우는 반복문
        nodes[edges[i][0]][edges[i][1]] = 1;
    }
    
    for(int i = 0; i < edges_rows; i++){
        if(stick(nodes, edges_rows, edges[i][1])){
            answer[2]++;
        }
    }
    
    return answer;
}

int main(){
    int edges[4][2] = {{2, 3}, {4, 3}, {1, 1}, {2, 1}};
    size_t edges_rows = 4;
    size_t edges_cols = 2;
    int* result = solution(edges, edges_rows, edges_cols);
}