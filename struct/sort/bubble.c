#include <stdio.h>

int main(){
	int data[] = {27, 32, 8, 40, 2, 37};
	int length = sizeof(data) / sizeof(int);
	for(int i = 0; i < length; i++){
		for(int j = 0; j < length - 1; j++){
			if(data[j] > data[j+1]){
				int temp = data[j];
				data[j] = data[j+1];
				data[j+1] = temp;
			}
		}
	}
	for(int i = 0; i < length; i++){
		printf("%d ", data[i]);
	}
	printf("\n%d\n", sizeof(data[0]));

	return 1;
}
