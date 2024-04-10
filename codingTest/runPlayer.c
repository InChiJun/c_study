// 문제: https://school.programmers.co.kr/learn/courses/30/lessons/178871

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int findIndex(const char** arr, const char* target, size_t len){
	for(int i = 0; i < len; i++){
		if(strcmp(arr[i], target) == 0){
			return i;
		}
	}
	return -1;
}

char** solution(const char* players[], size_t players_len, const char* callings[], size_t callings_len) {
	char** answer = (char**)malloc(players_len * sizeof(char*));
	int i;
	int index = 0;

	// answer에 값 복사
	for(i = 0; i < players_len; i++){
		answer[i] = players[i];
	}

	// callings 값 반영해서 answer 수정
	for(i = 0; i < callings_len; i++){
		index = findIndex(answer, callings[i], players_len);
		char* temp = answer[index];
		answer[index] = answer[index - 1];
		answer[index - 1] = temp;
	}

	return answer;
}

int main(){
	const char* players[] = {"mumu", "soe", "poe", "kai", "mine"};
	size_t players_len = 5;
	const char* callings[] = {"kai", "kai", "mine", "mine"};
	size_t callings_len = 4;

	const char** result = solution(players, players_len, callings, callings_len);

    
    for(int i = 0; i < players_len; i++){
        printf("%s\n", result[i]);
    }

	free(result);
    
	return 1;
}