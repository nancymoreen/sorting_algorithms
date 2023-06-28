#include "sort.h"
#include <stdio.h>

/**
 * swap - swaps two integers
 * @a: First integer
 * @b: Second integer
 */

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - Lomuto partition scheme to partition the array
 * @array: Array to be partitioned
 * @low: Starting index of the array
 * @high: Ending index of the array
 * @size: size of the array
 * Return: Index of the pivot element
 */

int partition(int *array, int low, int high, size_t size)
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
				print_array(array, size);
			}
		}
	}
	if (i + 1 != high)
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
* quicksort - Recursive function to sort the array using
* Quick sort algorithm
* @array: array to be sorted
* @low: Starting index of the partition
* @high: Ending index of the partition
* @size: Size of the array
*/

void quicksort(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot = partition(array, low, high, size);


		quicksort(array, low, pivot - 1, size);
		quicksort(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using
 * Quick sort algorithm
 * @array: Pointer to the first element of the array
 * @size: Size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;

	quicksort(array, 0, size - 1, size);
}
