#include "sort.h"
#include <stdio.h>
#include <stddef.h>

/**
 * bubble_sort - Sorts an array of integers in ascending order
 * using Bubble sort algorithm
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	int temp;

	if (array == NULL || size <= 1)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				print_array(array, size);
			}
		}
	}
}
