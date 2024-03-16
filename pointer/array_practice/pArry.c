#include <stdio.h>
int main(){
	char arry[] = "Hello world\n";
	char* pary = arry;

	printf("%d\n",pary);
	while(*pary++){ //arry의 주소가 담긴 pary를 increment operand함.
			//arry의 끝은 널문자(0)로 이루어져 있기 때문에 거짓에 해당
			//배열은 인덱스가 클수록 주소도 커진다.
		putchar(*pary); // 한 글자씩 출력
	}
	printf("%d\n",pary); //6번 라인에서 출력한 pary에 비해 13이 더해짐

	return 1;
}
