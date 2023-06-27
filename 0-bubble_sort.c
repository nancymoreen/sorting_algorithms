#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort - Sorts an array of integers in ascending order
 * using Bubble sort algorithm
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 */

void bubble_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;

	size_t x, y;
	int temp;

	for (x = 0, x < size - 1, x++)
	{
		for (y = 0, y < size - 1 - x, y++)
		{
			if (array[y] > array[y + 1])
			{
				temp = array[y];
				array[y] = array[y + 1];
				array[y + 1] = temp;

				print_array(array, size);
			}
		}
	}
}
