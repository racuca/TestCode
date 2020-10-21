#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
typedef struct _string {
    int sign;
    int flag;
}Giho;
typedef struct _node {
    void* data;
    struct Giho* next;
}Node;
typedef struct _linkedList {
    Node* head;
    Node* tail;
    Node* current;
}LinkedList;
void initializeList(LinkedList* list);
void addTail(LinkedList* list, void* data);
void display_node(LinkedList* list);
void print_sign(Giho* giho);
void sort_by_postfix(LinkedList* list);
void main() {
    LinkedList linkedList;
    initializeList(&linkedList);
    char ch;
    int cnt = 0;
    int temp[10]; // 문자열을 숫자로 변경하게끔 하는 배열 
    int i = 0;
    int j;
    int k;
    int temp_cnt;
    int sum = 0;
    printf("문자열 입력 : ");
    do {
        ch = fgetc(stdin);
        if ('0' <= ch && ch <= '9') {
            temp[i++] = ch - 0x30;
            cnt++;
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == ')') {
            Giho* atom1 = (Giho*)malloc(sizeof(Giho));
            Giho* atom2 = (Giho*)malloc(sizeof(Giho));
            temp_cnt = cnt;
            while (cnt > 0) {
                for (j = 0; j < cnt - 1; j++)
                    temp[j] *= 10;
                cnt--;
            }
            for (k = 0; k < temp_cnt; k++)
                sum += temp[k];
            printf("sum = %d\n", sum);
            atom1->sign = sum;
            atom1->flag = 1;
            addTail(&linkedList, atom1);
            atom2->sign = ch;
            if (ch != ')')
                atom2->flag = 0;
            else
                atom2->flag = 2;
            addTail(&linkedList, atom2);
            sum = 0;
            temp_cnt = 0;
            cnt = 0;
            i = 0;
        }
        else if (ch == '(') {
            Giho* atom3 = (Giho*)malloc(sizeof(Giho));
            atom3->sign = ch;
            atom3->flag = 2;
            addTail(&linkedList, atom3);
        }
        else if (ch == '\n')
            break;
    } while (ch != '\n');
    // 여기 위까지가 문자열 식을 구분하여 연결리스트에 집어 넣음. 
    sort_by_postfix(&linkedList);
    printf("\n");
    display_node(&linkedList);
}
void initializeList(LinkedList* list) {
    list->head = NULL;
    list->tail = NULL;
    list->current = NULL;
}
void addTail(LinkedList* list, void* data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    if (list->head == NULL) { // 첫 번째 노드가 없을 떄 
        list->head = node;
        node->next = NULL;
    }
    else {
        list->tail->next = node; // 기존의 노드의 next를 새로 만들어진 노드로 설정 
    }
    list->tail = node;
}
void display_node(LinkedList* list) {
    printf("\nLinked List\n");
    Node* current = list->head;
    while (current != NULL) {
        print_sign(current->data);
        current = current->next;
    }
}
void print_sign(Giho* giho) {
    printf("%d ", giho->sign);
}
int ret_flag(Giho* giho) {
    return giho->flag;
}
int ret_sign(Giho* giho) {
    return giho->sign;
}
void sort_by_postfix(LinkedList* list) { // 후위표기법으로 연결리스트 정렬 

    printf("\nSort by postfix method\n");
    Node* current = list->head;
    while (current != NULL) {
        Giho* g = current->data;
        if (g->flag == 1)
            printf("%d\n", g->sign);
        else 
            printf("%c\n", g->sign);
        current = current->next;
    }
}