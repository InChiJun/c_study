#include <stdio.h>
#include <string.h>

int main(){
	char str[20] = "hello world!!!\n";

	char str_c[20] = "good job!\n";

	printf("str_c = %s\n", str_c);
	strcpy(str_c, str);
	printf("str_c = %s\n", str_c);
	
	return 1;
}
