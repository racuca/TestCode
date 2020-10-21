#include <stdio.h>
#include <malloc.h>

typedef char element;
typedef struct DQNode {
	element data;
	struct DQNode* link;
} DQNode;

typedef struct {
	DQNode* front, * rear;
} DQueType;

// ���� ��ũ�� �����ϴ� ����
DQueType* createDQue()
{
	DQueType* DQ;
	DQ = (DQueType*)malloc(sizeof(DQueType));
	DQ->front = NULL;
	DQ->rear = NULL;
	return DQ;
}

// ��ũ�� ���� �������� �˻��ϴ� ����
int isEmpty(DQueType* const DQ)
{
	if (DQ->front == NULL) {
		printf("\n Linked Queue is empty! \n");
		return 1;
	}
	else
		return 0;
}

// ��ũ�� front ������ ���Ҹ� �����ϴ� ����
void insertFront(DQueType* DQ, element item)
{
	DQNode* newNode = (DQNode*)malloc(sizeof(DQNode));
	newNode->data = item;
	if (DQ->front == NULL) {   // ��ũ�� ���� ������ ���
		DQ->front = newNode;
		DQ->rear = newNode;
		newNode->link = NULL;
	}
	else {
		newNode->link = DQ->front;
		DQ->front = newNode;
	}
}

// ��ũ�� rear �ڷ� ���Ҹ� �����ϴ� ����
void insertRear(DQueType* DQ, element item)
{
	DQNode* newNode = (DQNode*)malloc(sizeof(DQNode));
	newNode->data = item;
	if (DQ->rear == NULL) {   // ��ũ�� ���� ������ ���
		DQ->front = newNode;
		DQ->rear = newNode;
		newNode->link = NULL;
	}
	else {
		DQ->rear->link = newNode;
		newNode->link = NULL;
		DQ->rear = newNode;
	}
}

// ��ũ�� front ��带 �����ϰ� ��ȯ�ϴ� ����
element deleteFront(DQueType* DQ)
{
	DQNode* old = DQ->front;
	element item;
	if (isEmpty(DQ)) return 0;
	else {
		item = old->data;
		if (DQ->front->link == NULL) {
			DQ->front = NULL;
			DQ->rear = NULL;
		}
		else {
			DQ->front = DQ->front->link;
		}
		free(old);
		return item;
	}
}

// ��ũ�� rear ��带 �����ϰ� ��ȯ�ϴ� ����
element deleteRear(DQueType* DQ)
{
	DQNode* old = DQ->rear;
	element item;
	if (isEmpty(DQ)) return 0;
	else {
		item = old->data;
		// rear ������ �缳�� rear - 1 ã�ƾ�...
		DQNode* rear_1 = DQ->front;
		while (rear_1->link != old)
		{
			rear_1 = rear_1->link;
		}
		DQ->rear = rear_1;
		
		// Rear Node link = null
		DQ->rear->link = NULL;

		free(old);
		return item;
	}
}

element peekFront(DQueType* DQ) {
	element item;
	if (isEmpty(DQ)) return 0;
	else {
		item = DQ->front->data;
		return item;
	}
}
element peekRear(DQueType* DQ) {
	element item;
	if (isEmpty(DQ)) return 0;
	else {
		item = DQ->rear->data;
		return item;
	}
}
void printDQ(DQueType* DQ) {
	DQNode* temp = DQ->front;
	printf("DeQue : [");
	while (temp) {
		printf("%3c", temp->data);
		temp = temp->link;
	}
	printf(" ] ");
}

void main(void) {
	DQueType* DQ1 = createDQue();  // ��ũ ����
	element data;
	printf("\n ***** ��ũ ���� ***** \n");
	printf("\n front ���� A>> ");  insertFront(DQ1, 'A');  printDQ(DQ1);   // A
	printf("\n front ���� B>> ");  insertFront(DQ1, 'B');  printDQ(DQ1);  // B A
	printf("\n rear  ���� C>> ");  insertRear(DQ1, 'C');  printDQ(DQ1);   // B A C
	printf("\n front ����  >> ");  data = deleteFront(DQ1);    printDQ(DQ1); // A C
	printf("\t���� ������: %c", data);
	printf("\n rear  ����  >> ");  data = deleteRear(DQ1);     printDQ(DQ1); // A
	printf("\t\t���� ������: %c", data);
	printf("\n rear  ���� D>> ");  insertRear(DQ1, 'D');  printDQ(DQ1);  // A D
	printf("\n front ���� E>> ");  insertFront(DQ1, 'E');  printDQ(DQ1);  // E A D
	printf("\n front ���� F>> ");  insertFront(DQ1, 'F');  printDQ(DQ1);  // F E  A D

	data = peekFront(DQ1);  printf("\n peek Front item : %c \n", data);  // F 
	data = peekRear(DQ1);  printf(" peek Rear item : %c \n", data);      // D
	getchar();
}