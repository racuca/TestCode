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
		print("1. �Է�\n");
		print("2. ����\n");
		print("3. ���\n");


	}
}