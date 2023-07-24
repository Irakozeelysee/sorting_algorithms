#include "sort.h"
/**
 * swap - swap two elements of an array
 * @i: pointer to the first element
 * @j: pointer to the second element
 */
void swap(int *i, int *j)
{
	int tmp;

	tmp = *i;
	*i = *j;
	*j = tmp;
}
/**
 * pivot - partition the array using pivot
 * @array: array to be sorted
 * @size: size of array
 * @low: low
 * @high: high
 * Return: index of the pivot element
 */
int pivot(int *array, size_t size, int low, int high)
{
	int *pivot, i, j;

	pivot = array + high;
	for (i = j = low; j < high; j++)
	{
		if (array[j] < *pivot)
		{
			if (i < j)
			{
				swap(array + j, array + i);
				print_array(array, size);
			}
			i++;
		}
	}

	if (array[i] > *pivot)
	{
		swap(array + i, pivot);
		print_array(array, size);
	}

	return (i);
}

/**
 * quickHelper - quick sort resursive function
 * @array: array to be sorted
 * @size: size of the array
 * @low: low
 * @high: high
 */
void quickHelper(int *array, size_t size, int low, int high)
{
	int pivotIndex;

	if (high > low)
	{
		pivotIndex = pivot(array, size, low, high);

		quickHelper(array, size, low, pivotIndex - 1);
		quickHelper(array, size, pivotIndex + 1, high);
	}
}

/**
 * quick_sort - sort an array with the quick sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quickHelper(array, size, 0, size - 1);
}
