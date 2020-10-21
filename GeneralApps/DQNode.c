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

// 공백 데크를 생성하는 연산
DQueType* createDQue()
{
	DQueType* DQ;
	DQ = (DQueType*)malloc(sizeof(DQueType));
	DQ->front = NULL;
	DQ->rear = NULL;
	return DQ;
}

// 데크가 공백 상태인지 검사하는 연산
int isEmpty(DQueType* const DQ)
{
	if (DQ->front == NULL) {
		printf("\n Linked Queue is empty! \n");
		return 1;
	}
	else
		return 0;
}

// 데크의 front 앞으로 원소를 삽입하는 연산
void insertFront(DQueType* DQ, element item)
{
	DQNode* newNode = (DQNode*)malloc(sizeof(DQNode));
	newNode->data = item;
	if (DQ->front == NULL) {   // 데크가 공백 상태인 경우
		DQ->front = newNode;
		DQ->rear = newNode;
		newNode->link = NULL;
	}
	else {
		newNode->link = DQ->front;
		DQ->front = newNode;
	}
}

// 데크의 rear 뒤로 원소를 삽입하는 연산
void insertRear(DQueType* DQ, element item)
{
	DQNode* newNode = (DQNode*)malloc(sizeof(DQNode));
	newNode->data = item;
	if (DQ->rear == NULL) {   // 데크가 공백 상태인 경우
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

// 데크의 front 노드를 삭제하고 반환하는 연산
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

// 데크의 rear 노드를 삭제하고 반환하는 연산
element deleteRear(DQueType* DQ)
{
	DQNode* old = DQ->rear;
	element item;
	if (isEmpty(DQ)) return 0;
	else {
		item = old->data;
		// rear 포인터 재설정 rear - 1 찾아야...
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
	DQueType* DQ1 = createDQue();  // 데크 생성
	element data;
	printf("\n ***** 데크 연산 ***** \n");
	printf("\n front 삽입 A>> ");  insertFront(DQ1, 'A');  printDQ(DQ1);   // A
	printf("\n front 삽입 B>> ");  insertFront(DQ1, 'B');  printDQ(DQ1);  // B A
	printf("\n rear  삽입 C>> ");  insertRear(DQ1, 'C');  printDQ(DQ1);   // B A C
	printf("\n front 삭제  >> ");  data = deleteFront(DQ1);    printDQ(DQ1); // A C
	printf("\t삭제 데이터: %c", data);
	printf("\n rear  삭제  >> ");  data = deleteRear(DQ1);     printDQ(DQ1); // A
	printf("\t\t삭제 데이터: %c", data);
	printf("\n rear  삽입 D>> ");  insertRear(DQ1, 'D');  printDQ(DQ1);  // A D
	printf("\n front 삽입 E>> ");  insertFront(DQ1, 'E');  printDQ(DQ1);  // E A D
	printf("\n front 삽입 F>> ");  insertFront(DQ1, 'F');  printDQ(DQ1);  // F E  A D

	data = peekFront(DQ1);  printf("\n peek Front item : %c \n", data);  // F 
	data = peekRear(DQ1);  printf(" peek Rear item : %c \n", data);      // D
	getchar();
}