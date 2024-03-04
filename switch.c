#include <stdio.h>

int main(){
	int option;
	scanf("%d", &option);

	switch(option){
		case 1:
			printf("Hello World!\n");
		case 2:
                       	 printf("Hello World!\n");
		case 3:
                        option = 3;
                        break;
		case 4:
                        option = 4;
                        break;
		default:
                        option = 0;
                        break;
	}
	printf("%d\n", option);
}
