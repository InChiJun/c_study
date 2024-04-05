#include <stdio.h>
#include <string.h>

int main(){
	char id[20];
	char* checkSpace = " ";
	
	do
    {
        printf("Please enter your name: ");
        fgets(id, 20, stdin);
    } while(strstr(id, checkSpace) != NULL);

	return 1;
}
