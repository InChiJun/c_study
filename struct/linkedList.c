#include <stdio.h>

typedef struct USERDATA{
	int nAge;
	char szName[16];
	char szPhone[16];
} userdata;

typedef struct NODE{
	userdata data;
} node;

int main(){
	userdata first = {26, "Daniel", "010-xxxx-xxx0"};

	printf("%s, %d, %s\n", first.szName, first.nAge, first.szPhone);

	return 1;
}
