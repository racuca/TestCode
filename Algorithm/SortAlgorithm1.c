#include <stdio.h>
#include <stdbool.h>
#define MAX 10

int* bubble_sort(int arr[], int n) {
    printf("Bubble Sort\n");
    printf("S :\t");
    for (int k = 0; k < n; k++) {
        printf("%d ", *(arr + k));
    }
    printf("\n");

    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        int bchange = 0;
        for (j = 0; j < (n-i)-1; j++) {
            if (arr[j] > arr[j + 1]) {

                printf("%d <-> %d\t", arr[j], arr[j + 1]);

                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;  

                bchange += 1;
            }
        }
        printf("\n%d :\t", i+1);
        for (int k = 0; k < n; k++) {
            printf("%d ", *(arr + k));
        }
        printf("\n");

        if (bchange <= 1)
            break;
    }
    return arr;
}

int* selection_sort(int arr[], int n)
{
    printf("Selection Sort\n");
    printf("S :\t");
    for (int k = 0; k < n; k++) {
        printf("%d ", *(arr + k));
    }
    printf("\n");


    int i, j, indexMin, temp;
    for (i = 0; i < n - 1; i++)
    {
        indexMin = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[indexMin])
            {
                indexMin = j;
            }
        }
        printf("%d <-> %d", arr[indexMin], arr[i]);
        temp = arr[indexMin];
        arr[indexMin] = arr[i];
        arr[i] = temp;

        printf("\n%d :\t", i+1);
        for (int k = 0; k < n; k++) {
            printf("%d ", *(arr + k));
        }
        printf("\n");
    }

    return arr;
}


int* insertion_sort(int* arr, int n)
{
    printf("Insertion Sort\n");
    printf("S :\t");
    for (int k = 0; k < n; k++) {
        printf("%d ", *(arr + k));
    }
    printf("\n");

    int i, j, datatomove;
    for (i = 1; i < n; i++)
    {
        datatomove = arr[(j = i)];
        printf("shifted values : ");
        while (--j >= 0 && datatomove < arr[j]) {
            arr[j + 1] = arr[j];
            printf("%d ", arr[j]);
        }
        arr[j + 1] = datatomove;
        printf("\nInserted value[%d] : %d\n", j + 1, datatomove);
    }
    return arr;
}

int main() {
    // 값 정의
    int arr[MAX] = { 10, 68, 2, 12, 6, 4, 8, 89, 45, 37 };
    //int arr[4] = { 1, 2, 3, 4 };

    // 배열 사이즈 계산 
    int arraylength = sizeof(arr) / sizeof(arr[0]);

    // bubble sort
    //int* arr_new = bubble_sort(arr, arraylength);
    // slection sort
    //int* arr_new = selection_sort(arr, arraylength);
    // insertion sort
    int* arr_new = insertion_sort(arr, arraylength);

    // 최종 데이터 출력
    printf("\nE :\t");
    for (int i = 0; i < arraylength; i++) {
        printf("%d ", *(arr_new + i));
    }
    printf("\n");
    return 0;
}