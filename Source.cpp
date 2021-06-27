#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>

void swap(int *m, int *n)
{
	int temp = *m;
	*m = *n;
	*n = temp;
}

void heapify(int arr[], int n, int i)		// To heapify a subtree rooted with node i which is an index in arr[]. n is size of heap
{
	int largest = i;						// Initialize largest as root
	int l = 2 * i + 1;						// left = 2*i + 1
	int r = 2 * i + 2;						 // right = 2*i + 2

	if (l < n && arr[l] > arr[largest])		// If left child is larger than root
		largest = l;

	if (r < n && arr[r] > arr[largest])		// If right child is larger than largest so far
		largest = r;

	if (largest != i)						// If largest is not root
	{
		swap(&arr[i], &arr[largest]);

		heapify(arr, n, largest);			// Recursively heapify the affected sub-tree
	}
}

void heapSort(int arr[], int n)				// main function to do heap sort
{
	for (int i = n / 2 - 1; i >= 0; i--)	// Build heap (rearrange array)
		heapify(arr, n, i);

	for (int i = n - 1; i > 0; i--)			// Build heap (rearrange array)
	{
		swap(&arr[0], &arr[i]);				// Move current root to end

		heapify(arr, i, 0);					// call max heapify on the reduced heap
	}
}

int main()
{
	int arr[20], n;
	printf("How many elements : ");
	scanf("%d", &n);
	printf("enter elements : \n");
	for (int i = 0; i<n; i++)
		scanf("%d", &arr[i]);

	heapSort(arr, n);

	printf("Sorted Array is  : ");
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);

	_getch();
}
