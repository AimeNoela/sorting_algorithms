#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * getMax - A utility function to get the maximum value in arr[]
 * @arr: array
 * @n: size of the array
 * Return: maximum value in the array
 */
int getMax(int *arr, int n)
{
	int i, max = arr[0];

	for (i = 1; i < n; i++)
		if (arr[i] > max)
			max = arr[i];
	return (max);
}

/**
 * countSort - A function to do counting sort of arr[] according to
 * the digit represented by exp.
 * @arr: array
 * @n: size of the array
 * @exp: exp is 10^i
 * @output: array to save the temporary values
 */
void countSort(int *arr, size_t n, int exp, int *output)
{
	int i;
	int count[10] = {0};

	/* Store count of occurrences in count[] */
	for (i = 0; i < (int)n; i++)
		count[(arr[i] / exp) % 10]++;
	/**
	 * Change count[i] so that count[i] now contains the actual
	 * position of this digit in output[]
	 */
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	/* Build the output array */
	for (i = n - 1; i >= 0; i--)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}
	/**
	 * Copy the output array to arr[], so that arr[] now
	 * contains sorted numbers according to the current digit
	 */
	for (i = 0; i < (int)n; i++)
		arr[i] = output[i];
}

/**
 * radix_sort - The main function to sort arr[] of size n using Radix Sort
 * @array: array
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	/* Find the maximum number to know the number of digits */
	int maximum = 0;
	/* Use unsigned int to avoid negative values of exp*/
	unsigned int exp = 1;
	int *output = NULL;

	if (array == NULL || size < 2)
		return;

	maximum = getMax(array, size);
	output = malloc(size * sizeof(int));
	if (output == NULL)
		return;

	while (maximum / exp > 0)
	{
		countSort(array, size, exp, output);
		exp *= 10;
	}
	free(output);
}
