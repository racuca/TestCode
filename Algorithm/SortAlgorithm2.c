#include <stdio.h>
#include <stdbool.h>
#define MAX 10


int* quick_sort(int* arr, int n)
{
    return arr;
}


int main() {
    // �� ����
    int arr[MAX] = { 10, 68, 2, 12, 6, 4, 8, 89, 45, 37 };
    
    // �迭 ������ ��� 
    int arraylength = sizeof(arr) / sizeof(arr[0]);

    // quick sort
    int* arr_new = quick_sort(arr, arraylength);

    // ���� ������ ���
    printf("\nE :\t");
    for (int i = 0; i < arraylength; i++) {
        printf("%d ", *(arr_new + i));
    }
    printf("\n");
    return 0;
}