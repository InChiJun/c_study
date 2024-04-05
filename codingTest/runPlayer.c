// 문제: https://school.programmers.co.kr/learn/courses/30/lessons/178871

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char** solution(const char* players[], size_t players_len, const char* callings[], size_t callings_len) {
	for(int i = 0; i < callings_len; i++){
	}
	char** answer = (char**)malloc(1);
	return answer;
}

int main(){
	const char* players[] = {"mumu", "soe", "poe", "kai", "mine"};
	size_t players_len = 5;
	const char* callings[] = {"kai", "kai", "mine", "mine"};
	size_t callings_len = 4;

	char** result = solution(players, players_len, callings, callings_len);

    /*
    for(int i = 0; i < 13; i++){
        printf("%s\n", a[i]);
    }
    */
}
