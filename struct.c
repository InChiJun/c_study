#include <stdio.h>
#include <string.h>

struct student{

	int s_id;
	char name[20];

};

int main(){

	struct student st1;
	st1.s_id = 3;
	strcpy(st1.name, "Daniel");

	printf("%d\n", st1.s_id);
	printf("%s\n", st1.name);
	
	printf("struct stdent size: %ld\n", sizeof(struct student));

	return 1;
}
