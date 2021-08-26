#include <stdio.h>
#include <time.h>

int binary_search(int* source_array, int count_elements, int item)
{
	clock_t begin = clock();
	int low = 0;
	int high = count_elements - 1;

	while (high > low)
	{
		int mid = (high + low) / 2;

		if (item == source_array[mid])
		{
			printf("Value %d is located at index of %d", item, mid);

			clock_t end = clock();
			double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
			printf("Function running time: %f\n", time_spent);

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

void selection_sort(int* unsorted_array, int count_elements)
{
	clock_t begin = clock();
	int tmp = 0;

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
		{
			if (unsorted_array[i] < unsorted_array[j])
			{
				tmp = unsorted_array[i];
				unsorted_array[i] = unsorted_array[j];
				unsorted_array[j] = tmp;
			}
		}

	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Function running time: %f\n", time_spent);
	return 0;
}

void countdown_recursion(int i)
{
	printf("%d\n", i);
	if (i <= 0)
		return 0;
	else
		countdown_recursion(i - 1);
}

int fact(int x)
{
	if (x == 1)
	{
		return 1;
	}
	return (x * fact(x - 1));
}

int subsequence_1_to_A(unsigned int A)
{
	if (A == 1)
	{
		printf("%d", 1);
		return 1;
	}
	printf("%d ", A);
	return subsequence_1_to_A(A - 1);
}

void qsordRecursive(int* unsorted_array, int count_elemetns)
{
	//Указатели на начало и конце массива
	int low = 0;
	int high = count_elemetns - 1;
	//Центральный элемент массива
	int mid = unsorted_array[count_elemetns / 2];
	//Делим массив
	do
	{
		//Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
		//В левой части массива пропускаем (оставляем на месте) элементы, которые меньше центрального
		while (unsorted_array[low] < mid)
		{
			low++;
		}

		//В правой части массива пропускаем элементы, которые больше центрального
		while (unsorted_array[high] > mid)
		{
			high--;
		}

		//Меняем элементы местами
		if (low <= high)
		{
			int tmp = unsorted_array[low];
			unsorted_array[low] = unsorted_array[high];
			unsorted_array[high] = tmp;

			low++;
			high--;
		}
	} while (low <= high);

	//Рекурсивные вызовы, если осталось что сортировать
	if (high > 0)
	{
		qsordRecursive(unsorted_array, high + 1);
	}

	if (low < count_elemetns)
	{
		qsordRecursive(unsorted_array, count_elemetns - low);
	}

}

int main()
{
	//Сортировка выбором и бинарный поиск
	//int source_arr[5] = { 9, 3, 5, 7, 1 };
	//selection_sort(source_arr, 5);
	//for(int i = 0; i < 5; i++)
	//	printf("%d\n", source_arr[i]);
	//binary_search(source_arr, 5, 1);

	//Быстрая сортировка и бинарный поиск
	//int source_arr[5] = { 9, 3, 5, 7, 1 };
	//qsordRecursive(source_arr, 5);
	//for(int i = 0; i < 5; i++)
	//	printf("%d\n", source_arr[i]);
	//binary_search(source_arr, 5, 1);

	//Факториал рекурсивной функцией
	//printf("%d\n", fact(5));

	//От 1 до А. Рекурсивная функция
	subsequence_1_to_A(5);

	//От A до B. Рекурсивная функция
	return 0;
}
