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
        while (arr[i] < pivot)	i++; // arr[i] ≥ pivot 일 때까지, left에서 오른쪽 방향으로 탐색
        while (arr[j] > pivot)	j--; // arr[j] ≤ pivot 일 때까지, right에서 왼쪽 방향으로 탐색

        if (i <= j) // 큰 값이 작은 값보다 왼쪽에 있으면
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
    // 배열 사이즈 계산 
    printf("\n%d(%d,%d) : ", printidx++, left, right);
    for (int len = 0; len < n; len++) {
        printf("%d ", *(arr + len));
    }
    printf("\n");

    /* 재귀함수 호출(recursive call) */
    if (left < j)	quick_sort(arr, n, left, j);
    if (i < right)	quick_sort(arr, n, i, right);

    return arr;
}

int main() {
    // 값 정의
    int arr[MAX] = { 10, 68, 2, 12, 6, 4, 8, 89, 45, 37 };
    
    // 배열 사이즈 계산 
    int arraylength = sizeof(arr) / sizeof(arr[0]);


    // 시작 데이터 출력
    printf("\nS :\t");
    for (int i = 0; i < arraylength; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");

    // quick sort
    int* arr_new = quick_sort(arr, arraylength, 0, arraylength - 1);

    // 최종 데이터 출력
    printf("\nE :\t");
    for (int i = 0; i < arraylength; i++) {
        printf("%d ", *(arr_new + i));
    }
    printf("\n");
    return 0;
}