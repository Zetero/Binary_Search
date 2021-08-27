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
}

int countdown_recursion(int i)
{
	printf("%d\n", i);
	if (i <= 0)
		return 0;
	else
		return countdown_recursion(i - 1);
}

int fact(int x)
{
	if (x == 1)
	{
		return 1;
	}
	return (x * fact(x - 1));
}

int helper_sub_1_to_A(unsigned int val, unsigned int max)
{
	if (val == max)
	{
		printf("%d", max);
		return max;
	}
	printf("%d ", val);
	return helper_sub_1_to_A(val + 1, max);
}

void subsequence_1_to_A(unsigned int max)
{
	int i = 1;
	helper_sub_1_to_A(i, max);
}

void subsequence_A_to_B(unsigned int A, unsigned int B)
{
	if (A == B)
	{
		printf("%d", A);
	}
	else if (A > B)
	{
		printf("%d ", A);
		subsequence_A_to_B(A - 1, B);
	}
	else if (A < B)
	{
		printf("%d ", A);
		subsequence_A_to_B(A + 1, B);
	}
}

int FunctionAkkerman(unsigned int n, unsigned int m)
{
	if (n == 0)
	{
		return m + 1;
	}
	else if (n != 0 && m == 0)
	{
		return FunctionAkkerman(n - 1, 1);
	}
	else if (n > 0 && m > 0)
	{
		return FunctionAkkerman(n - 1, FunctionAkkerman(n, m - 1));
	}
	return 0;
}

void Exact_power_of_two(unsigned int val)
{
	if (val == 2)
	{
		printf("Yes\n");
	}
	else if (val > 2)
	{
		Exact_power_of_two(val / 2);
	}
	else if (val < 2)
	{
		printf("No\n");
	}
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
	//subsequence_1_to_A(5);

	//От A до B (В обе стороны). Рекурсивная функция
	//subsequence_A_to_B(1, 5);

	//Функция Аккермана. Рекурсивная
	//printf("%d\n",FunctionAkkerman(2, 2));

	//Степень двойки. Рекурсия
	//Exact_power_of_two(128);
		
	return 0;
}
