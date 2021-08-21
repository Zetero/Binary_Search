#include <stdio.h>

int binary_search(int* source_array, int count_elements, int item)
{
	int low, mid, high, guess;
	low = 0;
	mid = 0;
	high = count_elements - 1;
	guess = source_array[mid];

	while (high > low)
	{
		mid = (high + low) / 2;
		guess = source_array[mid];
		if (guess == item)
			return mid;
		if (guess > item)
			high = mid;
		else
			low = mid;
	}
	return 0;
}

int main()
{
	int arr[5] = { 1, 3, 5, 7, 9 };
	int item = 7;
	printf("Position \"%d\" in array = %d", item, binary_search(arr, 5, item) + 1);
	return 0;
}
