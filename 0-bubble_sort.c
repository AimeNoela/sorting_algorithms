#include "sort.h"
/**
 * bubble_sort - sort array elements from min
 * to max value using bubble sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, index, tmp = 0;

	/* If the size of the array is less than 2, it is already sorted.*/
	if (size < 2)
		return;

	/* Outer loop for each pass of the bubble sort algorithm */
	for (i = 0; i < size; i++)
	{
		/* Inner loop to compare adjacent elements and swap if necessary */
		for (index = 0; index < size; index++)
		{
			/* Compare the current element with the next element */
			if (array[index] > array[index + 1] && array[index + 1])
			{
				/**
				 * Swap the elements if the current element
				 * is greater than the next element
				 */
				tmp = array[index];
				array[index] = array[index + 1];
				array[index + 1] = tmp;

				/* Print the array after each swap (to visualize the sorting process)*/
				print_array(array, size);
			}
		}
	}
}
