#include <stdio.h>

int main() {

    
    int num, temp;
    printf("�迭�� ����: ");
    scanf_s("%d", &num);
    int arr[10000];
    //printf("���� �Է�: ");
    for (int i = 0; i < num; i++) {
        scanf_s("%d", &arr[i]);
    }

    int cnt[10000] = { 0 };

    for (int i = 0; i < num; i++) {
        int arr2[5] = { 0,1,2,3,4 };
        for (int j = 0; j < num; j++) {
            for (int k = 0; k < 5; k++) {
                if (arr[j] - arr[i] == arr2[k]) {
                    cnt[i]++;
                    arr2[k] = 10000;
                }
            }
        }
    }

    int max = 0;
    for (int i = 0; i < num; i++) {
        if (cnt[i] >= 5) {
            printf("�ùٸ� �迭\n");
            return 0;
        }
        else if (cnt[i] > max) {
            max = cnt[i];
        }
    }
    printf("%d", 5 - max);

}