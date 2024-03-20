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

int main(){

