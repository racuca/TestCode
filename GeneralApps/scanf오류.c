
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_SIZE 10
char number[MAX_SIZE];

//����ȣ�� 0~9�����̸� �������ֵ��� �Ϸ��� �ҽ��ڵ带 �ۼ��� �����غôµ� 
//0~9�����̿� ���ڸ� �־ �߸��ƴٰ� ��ϴ� � ���� �����ΰɱ��
//void proc(int i) {
//
//	if (i >= MAX_SIZE) {
//		error_message(1);
//		return;
//	}
//
//	while (1) {
//		printf("����ȣ : ");
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
		printf("����ȣ : ");
		scanf("%s", &number);

		printf("%s", number);
}