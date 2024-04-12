// 출처: https://school.programmers.co.kr/learn/courses/30/lessons/154540

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool visit[105][105];
const int direct[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

typedef struct coordinate_{
    int h, w;
} coordinate;

int compare(void* a, void* b){
    return (*(int*) a > *(int*) b);
}

int Bfs(const char* maps[], coordinate st, int H, int W){
    int tesk = -1, did = -1;
    coordinate queue[10005];
    int total = 0;

    queue[++tesk] = st;
    visit[st.h][st.w] = 1;
    while(did < tesk){
        coordinate now = queue[++did];
        total += maps[now.h][now.w] - '0';

        for(int i = 0; i < 4; i++){
            coordinate move = {now.h + direct[i][0], now.w + direct[i][1]};

            if(move.h < 0 || move.w < 0 || move.h >= H || move.w >= W) // 범위를 벗어나는지 확인
                continue;
            if(maps[move.h][move.w] == 'X') // 식량이 있는지 확인
                continue;
            if(visit[move.h][move.w]) // 방문한 적이 있는지 확인
                continue;
            
            visit[move.h][move.w] = 1;
            queue[++tesk] = move;
        }
    }
    return total;
}

int* solution(const char* maps[], size_t maps_len) {
    int H = maps_len;
    int W = strlen(maps[0]);
    int* answer = NULL;
    int top = 0;

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(visit[i][j] == 1 || maps[i][j] == 'X')
                continue;
            
            coordinate st = {i, j};
            int res = Bfs(maps, st, H, W);

            answer = (int*)realloc(answer, sizeof(int) * (top+1));
            answer[top++] = res;
        }
    }

    if(top == 0){
        answer = (int*)realloc(answer, sizeof(int));
        top = 1;
        answer[0] = -1;
    }

    qsort(answer, top, sizeof(int), compare);

    return answer;
}

int main(){
    const char* maps[] = {"X591X", "X1X5X", "X231X", "1XXX1"};
    size_t maps_len = 4;

    int* result = solution(maps, maps_len);

    for(int i = 0; i < 3; i++){
        printf("%d\n", result[i]);
    }

    return 1;
}