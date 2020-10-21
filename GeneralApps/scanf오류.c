
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_SIZE 10
char number[MAX_SIZE];

//고객번호를 0~9번사이만 넣을수있도록 하려고 소스코드를 작성후 실행해봤는데 
//0~9번사이에 숫자를 넣어도 잘못됐다고 뜹니다 어떤 곳이 문제인걸까요
//void proc(int i) {
//
//	if (i >= MAX_SIZE) {
//		error_message(1);
//		return;
//	}
//
//	while (1) {
//		printf("고객번호 : ");
//		scanf("%s", &number[i]);
//		if (number[i] >= 0 && number[i] <= 9) {
//			break;
//		}
//		else {
//			error_message(2);
//		}
//	}
//}



void main()
{
		printf("고객번호 : ");
		scanf("%s", &number);

		printf("%s", number);
}