#include <stdio.h>
#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascendin
 * order using bubble sort.
 *
 * This function sorts an array of integers in ascending
 * order using the bubble sort algorithm.
 * Bubble sort repeatedly steps through the list, compares
 * adjacent elements, and swaps them if they are in the
 * wrong order.
 * The process is repeated until the array is sorted.
 *
 * @array: Pointer to the array of integers to be sorted.
 * @size: Number of elements in the array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, new = size;
	int swap = 1, a;

	while (swap)
	{
		swap = 0;
		for (i = 0; i < new; i++)
		{
			if (array[i] > array[i + 1])
			{
				a = array[i + 1];
				array[i + 1] = array[i];
				array[i] = a;
				swap = 1;
				print_array(array, size);
			}
			if (array[new - 2] < array[new - 1])
			{
				new -= 1;
			}
		}
	}
}
/**
 * print_array - Prints an array of integers.
 *
 * This function prints the elements of an integer
 * array to the standard output.
 *
 * @arr: Pointer to the array of integers.
 * @n: Number of elements in the array.
 */
void print_array(int *arr, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		if (i == 0)
		{
			printf("%d", arr[i]);
		}
		else
		{
			printf(", %d", arr[i]);
		}
	}
	printf("\n");
}
