#include <stdio.h>

int main(){
	int ary[] = {27, 32, 8, 40, 2, 37};
	int length = sizeof(ary) / sizeof(int);
	for(int i = length - 1; i > -1; i--){
		if(ary[i + 1] < ary[i]){

		}
	}

	for(int i = 0; i < length; i++){
		printf("%d ", data[i]);
	}
	printf("\n%d\n", sizeof(data[0]));

	return 1;
}
/*
for(n만큼 반복, 오른쪽에서 왼쪽으로--){
	if(오른쪽 값이 ary[i]보다 작다면){
		for(length - i만큼, 오른쪽에서 왼쪽으로--){
			if(ary[j]가 현재 값보다 작다면 || j가 i와 크기가 같다면){
				insertNum = 현재 값
				index = j;
				return;
			}
		}
		for(index부터, length - index만큼){
			temp = 현재 값;
			ary[j]에 insertNum 삽입
*/
