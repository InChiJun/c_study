#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* s) {
    int answer = 1;
    int sLen = strlen(s);

    for(int i = 1; i < sLen; i++){ // 1부터 순회
        int num = 1;
        if(s[i] == s[i - (num*2)]){ // 2칸 전 요소와 현재 인덱스가 같다면
            if(answer < num*2 + 1){
                answer = num*2 + 1;
            }

            for(int j = i+1; j < sLen; j++){ // i 다음 칸부터 탐색
                if(s[j - (num+1)*2] == s[j]){ // 현재 인덱스가 대칭된다면
                    num++;
                    if(answer < num*2 + 1){
                        answer = num*2 + 1;
                    }
                }else{
                    break;
                }
            }
        }
    }
    
    return answer;
}

int main(int argc, char const *argv[])
{
    const char* s = "abcdcba";

    int result = solution(s);
    printf("%d\n", result);

    return 0;
}
