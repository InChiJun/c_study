#include <string.h>
#include <stdio.h>

int main(){
	char str[] = "hello world!";

	char* strtoken = strtok(str, " ");

	printf("%s\n", strtoken);

	strtoken = strtok(NULL, " ");
	
	printf("%s\n", strtoken);
	
	return 1;
}
