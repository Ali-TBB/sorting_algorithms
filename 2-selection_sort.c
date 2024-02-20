#include "sort.h"

/**
 * selection_sort - Sorts an array of integers using selection sort.
 *
 * This function sorts an array of integers in ascending
 * order using selection sort.
 * Selection sort repeatedly selects the minimum element from
 * the unsorted subarray and moves it to the end of the sorted subarray.
 *
 *
 * @array: Pointer to the array of integers to be sorted.
 * @size: Number of elements in the array.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, a;
	int num, swap, flag;

	if (array == NULL)
		return;
	for (i = 0; i < size; i++)
	{
		num = i;
		flag = 0;
		for (a = i + 1; a < size; a++)
		{
			if (array[num] > array[a])
			{
				num = a;
				flag += 1;
			}
		}
		swap = array[i];
		array[i] = array[num];
		array[num] = swap;
		if (flag != 0)
			print_array(array, size);
	}
}
