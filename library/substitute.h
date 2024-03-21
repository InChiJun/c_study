#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* substitute(char* const origin, char* target, char* replace){
	int origin_len = strlen(origin);
	int target_len = strlen(target);
	int replace_len = strlen(replace);
	char* compare = malloc(target_len + 1);
	char* result = calloc(origin_len + replace_len - target_len + 1, sizeof(char));
	int result_len = origin_len + replace_len - target_len;

	for(int i = 0; i < origin_len; i++){
		if(origin[i] == target[0]){ // target
			for(int j = 0; j < target_len; j++){
				compare[j] = origin[i + j];
			}
			if(strcmp(compare, target) == 0){ // 찾았다면
				// target 전까지 문자열 복사
				for(int j = 0; j < i; j++){
					result[j] = origin[j];
				}
				//replace 문자 삽입
				int index = 0;
				for(int j = i; j < replace_len; j++){
					result[j] = replace[index];
					index++;
				}
				// replace 뒤 나머지 문자열 삽입
				index = i + target_len;
				for(int j = i + replace_len; j < result_len; j++){
					result[j] = origin[index];
					index++;
				}
				return result;
			}
		}
	}
}
