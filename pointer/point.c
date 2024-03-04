#include <stdio.h>

int main(){
	// Normal pointer
	int a = 1;
	int *pa;
	pa = &a;

	printf("a.address = %u\n", &a);
	printf("pa.address = %u\n", pa);

	printf("a = %d\n", a);
	printf("*pa = %d\n", *pa);

	printf("&a = %u\n", &a);
	printf("&pa = %u\n", &pa);

	*pa = 3;
	printf("*pa = %d\n", *pa);
	printf("a = %d\n", a);
	
	// double pointer
	int **ppa;
	ppa = &pa;
	printf("&ppa = %u\n", &ppa);
	printf("*ppa = %u\n", *ppa);
	printf("**ppa = %d\n", **ppa);

//	pa = 3;
//	printf("%d\n", pa);
//
//	printf("a.address = %d\n", &a);
//	printf("pa = %d\n", pa); // pa 자체 값 출력
//	printf("*pa = %d\n", *pa); // point로써 pa 출력
//	
//	*pa = &a;
//
//	printf("*pa = %d\n", &pa);
//	printf("a = %d", a);
	
	// Pointer size
	int * i;
	char * c;
	float * f;
	double * d;
	short * s;
	
	printf("%d\n", sizeof(i));
	printf("%d\n", sizeof(c));
	printf("%d\n", sizeof(f));
	printf("%d\n", sizeof(d));
	printf("%d\n", sizeof(s));

	return 1;
}
