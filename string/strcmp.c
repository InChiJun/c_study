#include <stdio.h>
#include <string.h>

int strcmp(const char* s1, const char* s2){
	for(int i = 0; s1

	return 1;
}

int main(){
	char* str1 = "helloa!";
	char* str2 = "hellobc";

	printf("%d\n", strcmp(str1, str2));

	return 1;
}
