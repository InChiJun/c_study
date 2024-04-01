#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

int a = 0;

void * thread1(void * arg){
	printf("arg : %d\n", (int)arg); 

	while(1){
		printf("thread1 a[%d]\n", ++a);
		sleep(2);
	}

	return NULL;
}

int main(){
	pthread_t s_thread;
	int b = 77;

	pthread_create(&s_thread, NULL, thread1, (void*)b);
			// 1. pthread_t 타입의 변수
			// 2. NULL
			// 3. thread 기능을 하는 함수
	pthread_join(s_thread, NULL);
