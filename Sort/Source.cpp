#include <iostream>
using namespace std;

void inputArray(int a[], int& n) {
	cout << "Input n: " << endl;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Input a[" << i << "]" << endl;
		cin >> a[i];
	}
}

void outputArray(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}

void InsertionSort(int a[], int n) {
	for (int i = 0; i < n; i++) {
		int j = i;
		while (j > 0 && a[j] < a[j - 1]) {
			swap(a[j], a[j - 1]);
			j--;
		}
	}
}

// MERGE SORT

void Merge(int a[], int left, int mid, int right) {
	int i, j, k;
	int L[100], R[100];
	int n1 = mid - left + 1;
	int n2 = right - mid;

	for (int i = 0; i < n1; i++) {
		L[i] = a[left + i];
	}
	for (int i = 0; i < n2; i++) {
		R[i] = a[mid + 1 + i];
	}
	i = 0;
	j = 0;
	k = left;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			a[k] = L[i];
			i++;
		}
		else {
			a[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		a[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		a[k] = R[j];
		j++;
		k++;
	}
}

void MergeSort(int a[], int left, int right) {
	if (left < right) {
		int mid = left + (right-left) / 2;
		MergeSort(a, left, mid);
		MergeSort(a, mid + 1, right);
		Merge(a, left, mid, right);
	}
}

// QUICK SORT
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

void QuickSort(int a[], int start, int end){
	if (start >= end) {
		return;
	}
	int p = partition(a, start, end);
	QuickSort(a, start, p - 1);
	QuickSort(a, p + 1, end);
}

// HEAP SORT
void Heapify(int a[], int n, int i) {
	int parent = i;
	int leftchild = 2 * i + 1;
	int rightchild = 2 * i + 2;
	
	if (leftchild < n && a[leftchild] > a[parent]) {
		parent = leftchild;
	}
	if (rightchild < n && a[rightchild] > a[parent]) {
		parent = rightchild;
	}
	if (parent != i) {
		swap(a[parent], a[i]);
	}
}

void HeapSort(int a[], int n) {
	for (int i = 0; i < n / 2 - 1; i++) {
		Heapify(a, n, i);
	}
	for (int i = n - 1; i > 0; i--) {
		swap(a[i], a[0]);
		Heapify(a, i, 0);
	}	
}


int main() {
	int a[100];
	int n;
	inputArray(a, n);
	outputArray(a, n);
	cout << endl;
	cout << "Input key: " << endl;
	int key;
	cin >> key;
	while (key != 0) {
		if (key == 1) {
			InsertionSort(a, n);
			outputArray(a, n);
		}
		if (key == 2) {
			MergeSort(a, 0, n - 1);
			outputArray(a, n);
		}
		if (key == 3) {
			QuickSort(a, 0, n - 1);
			outputArray(a, n);
		}
		if (key == 4) {
			HeapSort(a, n);
			outputArray(a, n);
		}
		cout << endl;
		cout << "Input key: " << endl;
		cin >> key;
		if (key == 0) {
			break;
		}
	}
	return 0;
}