#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void SelSortUD(double arr[], int size, int up);

int main(void)
{
	int arr[10] = { 5, 1, 2, 7, 8, 3, 9, 4, 10, 6 };
	int i, up;

	printf("오름차순 0, 내림차순 1 : ");
	scanf("%d", &up);

	SelSortUD(arr, 10, up);

	if (up == 0)
	{
		printf("오름차순 정렬 결과 : ");
		for (i = 0; i < 10; i++)
			printf("%d ", arr[i]);
		printf("\n");
	}

	else if (up == 1)
	{
		printf("내림차순 정렬 결과 : ");
		for (i = 0; i < 10; i++)
			printf("%d ", arr[i]);
		printf("\n");
	}

	return 0;
}

void SelSortUD(int arr[], int size, int up)
{
	int i, j, temp, index;

	if (up == 0)
	{
		for (i = 0; i < 9; i++)
		{
			index = i;
			for (j = i + 1; j < 10; j++)
			{
				if (arr[index] > arr[j])
					index = j;
			}
			temp = arr[i];
			arr[i] = arr[index];
			arr[index] = temp;
		}
	}
	else if (up == 1)
	{
		int i, j, temp, index;

		for (i = 0; i < 9; i++)
		{
			index = i;
			for (j = i + 1; j < 10; j++)
			{
				if (arr[index] < arr[j])
					index = j;
			}
			temp = arr[i];
			arr[i] = arr[index];
			arr[index] = temp;
		}
	}
}
