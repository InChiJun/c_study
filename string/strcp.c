#include <stdio.h>

char* strcpy(char* dest, const char* src){
	for(int i = 0; src[i] != 0; i++){
		dest[i] = src[i];
	}
	/*
	while(*src){
		*dest++ = *src++;
	}
	*/

	return dest;
}

int main(){
	char str_src[20] = "hello world!!!";
	char str_dst[20];

	strcpy(str_dst, str_src);
	printf("%s\n", str_dst);

	return 1;
}
