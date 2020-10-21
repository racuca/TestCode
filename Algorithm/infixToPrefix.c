#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "ListBaseStack.h"

// �Ű������� �������� �������ִ� �Լ�
void Reverse_exp(char *exp) {
	int i = 0, j = 0;
	int len = strlen(exp);

	char *a = (char *)malloc(sizeof(char)*(len + 1));

	Stack stack;

	// ���� �ʱ�ȭ
	StackInit(&stack);

	for (i = 0; i < len; i++) {
		a[i] = exp[i];
	}

	for (i = 0; i < len; i++) {
		SPush(&stack, a[i]);
	}

	for (i = 0; i < len; i++) {
		exp[i] = SPop(&stack);
	}
}

char* infix_to_prefix(char exp[]) {
	int i = 0, j = 0;
	char ch, top_op;
	int len = strlen(exp);

	char *ex = (char*)malloc(sizeof(char)*(len + 1));

	Stack stack;
	StackInit(&stack);

	for (i = len - 1; i >= 0; i--) {
		ch = exp[i];
		switch (ch) {
		case '+':
		case '-':
		case '*':
		case '/':
			while (!SIsEmpty(&stack) && WhoPrecOp(SPeek(&stack), ch) >= 0) { // ���ÿ� �ִ� �����ڰ� �� ũ�� ������ �߰�
				ex[j++] = SPop(&stack);
			}
			SPush(&stack, ch);
			break;
		case ')':
			SPush(&stack, ch);
			break;
		case '(':
			top_op = SPop(&stack);
			while (top_op != ')') {
				ex[j++] = top_op;
				top_op = SPop(&stack);
			}
			break;
		default:
			ex[j++] = ch;
			break;
		}
	}

	while (!SIsEmpty(&stack)) {
		ex[j++] = SPop(&stack);
	}

	ex[j] = NULL;

	Reverse_exp(ex);

	return ex;
}
