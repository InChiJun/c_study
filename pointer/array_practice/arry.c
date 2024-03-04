#include <stdio.h>

int main(){
	int arryA[10];

	for(int i = 0; i < 5; i++){
		arryA[i] = i;
	}

	for(int i = 0; i < 10; i++){
		printf("arryA[%d] = %d\n", i, arryA[i]);
	}

	return 0;
}
