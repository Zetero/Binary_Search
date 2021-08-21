#include <stdio.h>

int binary_search(int* source_array, int count_elements, int item)
{
	int low = 0;
	int high = count_elements - 1;

	while (high > low)
	{
		int mid = (high + low) / 2;

		if (item == source_array[mid])
		{
			printf("Value %d is located at index of %d", item, mid);
			return 0;
		}
		else if (item > source_array[mid])
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	return 1;
}

int main()
{
	int source_arr[5] = { 1, 3, 5, 7, 9};
	binary_search(source_arr, 5, 7);
	return 0;
}
