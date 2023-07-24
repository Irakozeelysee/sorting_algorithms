#include <stdio.h>
#include "sort.h"

/**
 * swap - swap two elements of an array
 * @i: pointer to the first element
 * @j: pointer to the second element
 */
void swap(int *i, int *j)
{
	int tmp = *i;
	*i = *j;
	*j = tmp;
}

/**
 * lomuto_partition - partition the array using Lomuto scheme
 *
 * @array: array to be sorted
 * @low: starting index of the partition
 * @high: ending index of the partition
 *
 * Return: index of the pivot element
 */
int lomuto_partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, high + 1);
			}
		}
	}
	if (i + 1 != high)
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, high + 1);
	}
	return (i + 1);
}

/**
 * quick_sort_recursive - recursive function to perform Quick sort
 *
 * @array: array to be sorted
 * @low: starting index of the partition
 * @high: ending index of the partition
 */
void quick_sort_recursive(int *array, int low, int high)
{
	int pivot;

	if (low < high)
	{
		pivot = lomuto_partition(array, low, high);
		quick_sort_recursive(array, low, pivot - 1);
		quick_sort_recursive(array, pivot + 1, high);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order using Quick sort
 *              algorithm with Lomuto partition scheme.
 *
 * @array: array to be sorted
 * @size: number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_recursive(array, 0, size - 1);
}
