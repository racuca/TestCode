
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
    int j, ori; //j�� ���۰�
    int count = 0; //�� ȸ ��ȯ�� ������ ����
    printf("���۰��� �Է��ϼ��� : ");
    scanf("%d", &j);
    ori = j;//�ʱⰪ ���� (����printf�� ���)
    while (1) {
        if (j != 1)
        {
            if (j % 2 == 0)
            {
                j = j / 2;
                count++;
            }
            else
            {
                j = 3*j + 1;
                count++;
            }
        }
        else
        {
            printf("%dȸ ��, %d�� 1�� �˴ϴ�.", count, ori);
            return 0;
        }

    }
    printf("���α׷��� �����մϴ�.");
    return 0;
}