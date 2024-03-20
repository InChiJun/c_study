#include <stdio.h>

int linearSum(int num){
	if(num > 1){
		return num + linearSum(num - 1);
	}
}

int main(){
	int userNum = 0;
	// printf("please write Number: ");
	// scanf("%d", &userNum);
	
	int result = linearSum(3);
	printf("%d\n", result);

	return 1;
}