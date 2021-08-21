#include <stdio.h>
#include <stdbool.h>

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
			high = mid - 1;
		else
			low = mid + 1;
	}
	return 0;
}

int main()
{
	int arr[5] = {0, 0, 0, 0,0 };
	Test_Binary_Search();
	return 0;
}