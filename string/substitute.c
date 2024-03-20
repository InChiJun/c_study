#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* substitute(char* const origin, char* target, char* replacement){
	size_t origin_len = strlen(origin);
	size_t target_len = strlen(target);
	size_t replacement_len = strlen(replacement);

	for(int i = 0; i < origin_len; i++){
		for(int j = 0; j < 
		if(origin[i] == 

}

int main(){
	char* origin = "hello world!";
	char* target = "hello";
	char* replacement = "hi";

	// char* result = substitute(origin, target, replacement);
	
	printf("%c\n", origin[1]);

	return 1;
}
