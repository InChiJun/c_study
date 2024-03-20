#include <stdio.h>

int factorial(int num){
	if(num > 1){
		return num * factorial(num - 1);
	}
}

int main(){
	int userNum = 0;
	printf("please write Number: ");
	scanf("%d", &userNum);
	
	int result = factorial(userNum);
	printf("%d\n", result);

	return 1;
}
