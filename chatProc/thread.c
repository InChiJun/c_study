#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

int a = 0;

void * thread1(void * arg){
	printf("arg : %d\n", (int)arg); 

	while(1){
		printf("thread1%d a[%d]\n", (int)arg, ++a);
		sleep(2);
	}

	return NULL;
}

int main(){
	pthread_t s_thread[2];
	int id1 = 77;
	int id2 = 88;

	pthread_create(&s_thread[0], NULL, thread1, (void*)id1);
	pthread_create(&s_thread[1], NULL, thread1, (void*)id2);
			// 1. pthread_t 타입의 변수
			// 2. NULL
			// 3. thread 기능을 하는 함수
	pthread_join(s_thread[0], NULL);
	pthread_join(s_thread[1], NULL);

	return 1;
}