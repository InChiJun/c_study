#include <stdio.h>

size_t strlen(const char *s){
	size_t size = 0;

	while(*s){
		*s++;
		size++;
	}

	return size;
}

int main(){
	char* str = "hello world!";

	printf("%ld\n", strlen(str));
	
	return 1;
}
