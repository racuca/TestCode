#include <stdio.h>

int BinarySearch(int arr[], int len, int target)
{
	printf("target : %d\n", target);

	int first = 0;
	int last = len - 1;
	int mid = 0;

	while (first <= last) {
		mid = (first + last) / 2;
		printf("middle index is %d\n", mid);

		if (arr[mid] == target) {
			return mid;
		}
		else if (arr[mid] < target) {
			first = mid + 1;
		}
		else {
			last = mid - 1;
		}
	}

	return -1;

}

void main() 
{
	int array[10] = { 1, 3, 8, 10, 14, 18, 20, 24, 35, 50 };

	int result = BinarySearch(array, 10, 60);

	printf("Found result is %d\n", result);
}