#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

#define DATASET_SIZE 50000

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

void Insertion(int data[], int size)
{
        int count=0;
        int j=0;
        for(int i=1;i<size;i++)
        {
                j=i;
                int temp=data[j];
                while(j>=1 && data[j]<data[j-1])
                {
                        data[j]=data[j-1];
                        data[j-1]=temp;
                        j--;
                        count++;
                }
        }
        printf("run count: %d\n",count);
}

int main(){
	struct timeval tv;
	double begin, end;
	int* dataset = malloc(sizeof(int)*50000);
	dataset = makeRandomNumber(dataset);

	gettimeofday(&tv, NULL);
	begin = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
	Insertion(dataset, DATASET_SIZE);
	gettimeofday(&tv, NULL);
	end = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
	
	printNumber(dataset);
	printf("\ntime = %f\n", (end - begin) / 1000);
	free(dataset);	

	return 1;
}
