#define _CRT_SECURE_NO_WARNINGS    // fopen ���� ���� ���� ������ ���� ����
#include <stdio.h>     // fopen, fwrite, fclose �Լ��� ����� ��� ����
#include <string.h>    // strlen �Լ��� ����� ��� ����

int main()
{
	char *s1 = "Hello, world!";
	char data[20];
	char buffer1[100], buffer2[100];

	FILE *fp = fopen("hello.txt", "a");    // hello.txt ������ ���� ���(w)�� ����.
										   // ���� �����͸� ��ȯ
	fputs("Hello, world!", fp);    // ���Ͽ� ���ڿ� ����
	fputs("Hello, world2!", fp);    // ���Ͽ� ���ڿ� ����
	fwrite(s1, strlen(s1), 1, fp);    // strlen���� ���ڿ��� ���̸� ����.
									  // ���ڿ��� ���̸�ŭ 1�� ���Ͽ� ����

	fclose(fp);    // ���� ������ �ݱ�

	
	fp = fopen("hello.txt", "r");
	fgets(buffer1, sizeof(buffer1), fp); // ���ٸ� ����
	fgets(buffer2, sizeof(buffer2), fp); // ���ٸ� ����
	fread(buffer1, sizeof(buffer1), 1, fp);   // hello.txt���� ���� ũ��(20����Ʈ)��ŭ 1�� ���� ����
	while (fscanf(fp, "%s", &data) != EOF) {
		printf("%d\n", data);
	}

	fclose(fp);

	return 0;
}