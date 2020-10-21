#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    int num;
    int count;

    printf("숫자입력:  ");
    scanf_s("%d", &num);

    for (int i = 1; i <= num; i++)
    {
        count = 0;

        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                count++;
                break;
            }

        }
        if (count == 0)
        {
            printf("%d", i);
        }
    }
    printf("\n");

    return 0;
}