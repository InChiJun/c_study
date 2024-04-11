// 출처: https://school.programmers.co.kr/learn/courses/30/lessons/154540

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// maps_len은 배열 maps의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.

typedef struct node_
{
    int h,w;
} node;

int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

bool visit[105][105];

int BFS(const char* map[], node st, int H,int W)
{
    node queue[10005];
    int f=-1,r=-1;

    queue[++r] = st;
    visit[st.h][st.w] = 1;

    int tot = 0;
    while(f<r)
    {
        node now = queue[++f];
        tot += map[now.h][now.w] - '0';

        for(int i=0;i<4;i++)
        {
            node move = {now.h + dir[i][0], now.w + dir[i][1]};

            if(move.h < 0 || move.w <0 || move.h >= H || move.w >= W) 
                continue;
            if(map[move.h][move.w] == 'X' || visit[move.h][move.w])
                continue;

            queue[++r] = move;
            visit[move.h][move.w] = 1;
        }
    }
    return tot;
}

int compare(void *a, void *b)
{
    return (*(int *)a > *(int *)b);
}

int* solution(const char* maps[], size_t maps_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = NULL;
    int top = 0;

    int H = maps_len;
    int W = strlen(maps[0]);

    for(int i=0;i<H;i++)
    {
        for(int j=0;j<W;j++)
        {
            if(maps[i][j] == 'X' || visit[i][j]) continue; // X가 아니며, 방문하지 않은 곳을 찾기

            node st = {i,j};
            int res = BFS(maps,st,H,W);

            answer = (int *)realloc(answer, sizeof(int) * (top+1));
            answer[top++] = res;
        }
    }

    if(top == 0)
    {
        answer = (int *)malloc(sizeof(int));
        top = 1;
        answer[0] = -1;
    }

    qsort(answer, top, sizeof(int), compare);

    return answer;
}

int main(){
    const char* maps[] = {"X591X","X1X5X","X231X", "1XXX1"};
    size_t maps_len = 4;

    int* result = solution(maps, maps_len);

    for(int i = 0; i < 3; i++){
        printf("%d\n", result[i]);
    }

    return 1;
}