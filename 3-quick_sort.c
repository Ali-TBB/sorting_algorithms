#include "sort.h"
/**
 * swap - Swaps two elements in an array
 * @array: Pointer to the array
 * @a: Index of the first element to swap
 * @b: Index of the second element to swap
 */
void swap(int *array, ssize_t a, ssize_t b)
{
	int tmp;

	tmp = array[a];
	array[a] = array[b];
	array[b] = tmp;
}
/**
 * partition - Lomuto partition scheme implementation
 * @array: Pointer to the array to be partitioned
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 *
 * Return: Index of the pivot element after partitioning
 */
int partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	int pivot = array[high];
	ssize_t current = low, i;

	for (i = low; i < high; i++)
	{
		if (array[i] < pivot)
		{
			if (array[current] != array[i])
			{
				swap(array, current, i);
				print_array(array, size);
			}
			current++;
		}
	}
	if (array[current] != array[high])
	{
		swap(array, current, high);
		print_array(array, size);
	}
	return (current);
}
/**
 * quick_sort_helper - Recursively sorts a segment of an array
 * using the quicksort algorithm
 * @array: Pointer to the array to be sorted
 * @low: Starting index of the segment to be sorted
 * @high: Ending index of the segment to be sorted
 * @size: Size of the array
 */
void quick_sort_helper(int *array, ssize_t low, ssize_t high, int size)
{
	ssize_t p = 0;


	if (low < high)
	{
		p = partition(array, low, high, size);

		quick_sort_helper(array, low, p - 1, size);
		quick_sort_helper(array, p + 1, high, size);
	}
}
/**
 * quick_sort - Sorts an array of integers using quicksort
 * @array: Pointer to the array to be sorted
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quick_sort_helper(array, 0, size - 1, size);
}
