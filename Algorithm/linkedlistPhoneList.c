#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct _Phone {
	char name[20];
	char phonenum[12];
	struct _Phone * next;
} Phone;

typedef struct _PhoneList
{
	Phone* head;
	Phone* tail;
} PhoneList;

void ListInit(PhoneList* list) 
{
	list->head = 0;
	list->tail = 0;
}

void AddPhone(PhoneList* list, Phone* p) {
	p->next = 0;

	if (list->head == 0)
	{
		list->head = p;
		list->tail = p;
		return;
	}

	list->tail->next = p;
	list->tail = p;
}


void RemovePhone(PhoneList* list, Phone* p) {

	Phone* temp = list->head;
	Phone* previous = list->head;

	while (temp != 0) {
		if (temp == p) {
			Phone* tempnext = temp->next;
			previous->next = tempnext;
			if (temp == list->head)
				list->head = tempnext;
			free(temp);
			break;
		}
	}
}

int RemovePhonebyName(PhoneList* list, char* name) {
	
	Phone* temp = list->head;
	Phone* previous = list->head;
	while (temp != 0) {
		if (strcmp(temp->name, name) == 0)
		{
			RemovePhone(list, temp);
			break;
		}
		previous = temp;
		temp = temp->next;
	}
}



void main()
{
	PhoneList list;
	ListInit(&list);
	int bstop = 0;
	int menu = 0;

	while (!bstop) {
		
		//system("cls");
		printf("1. �Է�\n2.����\n3.���\n�޴��� �Է��ϼ��� : ");
		scanf("%d", &menu);
		switch (menu) {
			case 1:
			{
				Phone* p = malloc(sizeof(Phone));
			
				printf("\n�̸� ��ȭ��ȣ �Է� : ");
				scanf("%s %s", p->name, p->phonenum);
				AddPhone(&list, p);
			}
			break;
			case 2:
			{
				char name[20] = {0};
				printf("\n������ �̸� : ");
				scanf("%s", name);
				RemovePhonebyName(&list, name);
			}
			break;
			case 3:
			{
				printf("���:\n");

				Phone* p = list.head;
				while (p != 0) {
					printf("�̸�, ��ȭ��ȣ : %s %s\n", p->name, p->phonenum);
					p = p->next;
				}
			}
			break;
		}
	}

	Phone* p = malloc(sizeof(Phone));

}