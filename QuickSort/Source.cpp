// C++ Implementation of the Quick Sort Algorithm.
#include <iostream>
using namespace std;

int partition(int arr[], int low, int high, int pivot) {
	int i = low;
	int j = low;
	while (i <= high) {
		if (arr[i] > pivot) {
			i++;
		}
		else {
			swap(arr[i], arr[j]);
			i++;
			j++;
		}
	}
	return j - 1;
}

void print(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}

void quickSort(int arr[], int low, int high) {
	if (low < high) {
		int pivot = arr[high];
		int pos = partition(arr, low, high, pivot);

		quickSort(arr, low, pos - 1);
		quickSort(arr, pos + 1, high);
	}
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
