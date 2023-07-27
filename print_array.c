#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
	size_t i;

	/* Initialize the index 'i' to 0 */
	i = 0;

	/* Check if 'array' is not NULL and loop through the elements of the array */
	while (array && i < size)
	{
		/**
		 * Print a comma and space before printing the current element
		 * if it's not the first element
		 */
		if (i > 0)
			printf(", ");

		/*Print the current element at index 'i' */
		printf("%d", array[i]);

		/* Increment the index to move to the next element */
		++i;
	}
	/* Print a newline character after printing all the elements */
	printf("\n");
}
