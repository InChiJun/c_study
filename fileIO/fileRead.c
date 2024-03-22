#include <stdio.h>

void fileTest(){
	char szBuffer[128] = {0};
	FILE* fp = fopen("test.csv", "r");
	fgets();

	while(fgets(szBuffer, 128, fp)){
		printf("%s\n", szBuffer);

int main(){
	FILE *fp;

	fp = fopen("test.txt", "r");



	fclose(fp);

	return 1;
}
