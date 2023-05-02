#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main() {
    int a[1000] = {0,};
    int call;
    scanf("%d ", &call);
    for (int i = 0; i < call; i++) {
        scanf("%d", &a[i]);
    }
    for (int j = call - 1; j >= 0; j--) {
        printf("%d ", a[j]);
    }
    return 0;
}


/*
#include <stdio.h>

int main() {
    int num, arr[10000];
    scanf("%d", &num);

    for (int i = 0; i < num; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = num - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    return 0;
}
*/