#include "substitute.h"

int main(){
	char* origin = "hello world!, hello universe, hello Daniel";
	char* target = "hello";
	char* replace = "hi";
	
	printf("%s\n", substitute(origin, target, replace));
	
	return 1;
}
