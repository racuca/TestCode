#include <stdio.h>
#include <stdbool.h>
#define MAX 10

int printidx = 0;

int* quick_sort(int arr[], int n, int left, int right) {
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];
    int temp;

    while (i <= j)
    {
        while (arr[i] < pivot)	i++; // arr[i] �� pivot �� ������, left���� ������ �������� Ž��
        while (arr[j] > pivot)	j--; // arr[j] �� pivot �� ������, right���� ���� �������� Ž��

        if (i <= j) // ū ���� ���� ������ ���ʿ� ������
        {
            // SWAP arr[i] and arr[j]
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            printf("%d <-> %d, ", i, j);

            i++;
            j--;
        }
    }
    // �迭 ������ ��� 
    printf("\n%d(%d,%d) : ", printidx++, left, right);
    for (int len = 0; len < n; len++) {
        printf("%d ", *(arr + len));
    }
    printf("\n");

    /* ����Լ� ȣ��(recursive call) */
    if (left < j)	quick_sort(arr, n, left, j);
    if (i < right)	quick_sort(arr, n, i, right);

    return arr;
}

int main() {
    // �� ����
    int arr[MAX] = { 10, 68, 2, 12, 6, 4, 8, 89, 45, 37 };
    
    // �迭 ������ ��� 
    int arraylength = sizeof(arr) / sizeof(arr[0]);


    // ���� ������ ���
    printf("\nS :\t");
    for (int i = 0; i < arraylength; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");

    // quick sort
    int* arr_new = quick_sort(arr, arraylength, 0, arraylength - 1);

    // ���� ������ ���
    printf("\nE :\t");
    for (int i = 0; i < arraylength; i++) {
        printf("%d ", *(arr_new + i));
    }
    printf("\n");
    return 0;
}