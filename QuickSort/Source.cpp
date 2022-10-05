// C++ Implementation of the Quick Sort Algorithm.
#include <iostream>
using namespace std;

int partition(int a[], int start, int end) {
	int pivot = a[start];
	int count = 0;
	for (int i = start+1; i <= end; i++) {
		if (a[i] <= pivot) {
			count += 1;
		}
	}
	int pivotIndex = start + count;
	swap(a[pivotIndex], a[start]);

	int i = start, j = end;
	while (i<pivotIndex && j>pivotIndex) {
		while (a[i] <= pivot) {
			i++;
		}
		while (a[j] > pivot) {
			j--;
		}
		while (i<pivotIndex && j>pivotIndex) {
			swap(a[i], a[j]);
			i++;
			j++;
		}
	}
	return pivotIndex;
}

void quickSort(int arr[], int start, int end)
{

	// base case
	if (start >= end)
		return;

	// partitioning the array
	int p = partition(arr, start, end);

	// Sorting the left part
	quickSort(arr, start, p - 1);

	// Sorting the right part
	quickSort(arr, p + 1, end);
}

int main()
{

	int arr[] = { 9, 3, 4, 2, 1, 8 };
	int n = 6;

	quickSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}
