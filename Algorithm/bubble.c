#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

#define DATASET_SIZE 50000

/*
struct timeval{
	long tv_sec;
	long tv_usec;
};
*/

int *makeRandomNumber(int *dataset){
	int i;
	srand(0);
	for(i = 0; i < DATASET_SIZE; i++){
		dataset[i] = rand() % DATASET_SIZE;
	}
	return dataset;
}
void printNumber(int number[]){
	for(int i = 0; i < DATASET_SIZE; i++){
		if((i < 100) || (i > DATASET_SIZE - 100)){
			printf("%10d ", number[i]);
			if(i % 9 == 0){
				printf("\n");
			}
			if(i == 100){
				printf("\n");
			}
		}
	}
}

void bubble(int *arry, int length){
	for(int i = 0; i < length; i++){
		for(int j = 0; j < length - 1; j++){
			if(arry[j] > arry[j+1]){
				int temp = arry[j];
				arry[j] = arry[j+1];
				arry[j+1] = temp;
			}
		}
	}
}

int main(){
	struct timeval tv;
	double begin, end;
	int* dataset = malloc(sizeof(int)*50000);
	dataset = makeRandomNumber(dataset);

	gettimeofday(&tv, NULL);
	begin = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
	bubble(dataset, DATASET_SIZE);
	gettimeofday(&tv, NULL);
	end = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
	
	printNumber(dataset);
	printf("\ntime = %f\n", (end - begin) / 1000);
	free(dataset);	

	return 1;
}
