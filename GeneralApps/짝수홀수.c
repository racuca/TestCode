
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
    int j, ori; //j는 시작값
    int count = 0; //몇 회 순환을 도는지 측정
    printf("시작값을 입력하세요 : ");
    scanf("%d", &j);
    ori = j;//초기값 저장 (최종printf에 사용)
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
            printf("%d회 후, %d는 1이 됩니다.", count, ori);
            return 0;
        }

    }
    printf("프로그램을 종료합니다.");
    return 0;
}