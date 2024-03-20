#include <stdio.h>

void test() {
	printf("test\n");
}
void test22() {
	printf("test22\n");
}

int main() {
	void (*fp)();
	
	fp = test;
	fp();

	fp = test22;
	fp();

	return 1;
}
