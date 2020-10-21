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


void main()
{
	while (1) {
		print("1. 입력\n");
		print("2. 삭제\n");
		print("3. 출력\n");


	}
}