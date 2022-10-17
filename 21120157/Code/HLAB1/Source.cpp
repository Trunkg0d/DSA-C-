//21120157
//Lê Phạm Hoàng Trung
#include <iostream>
#include <time.h>
using namespace std;

//Print Array
void output(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

// SELECTION SORT
void SelectionSort(int a[], int n) {
	for (int i = 0; i < n; i++) {
		int min_pos = i;
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[min_pos]) {
				min_pos = j;
			}
		}
		if (a[min_pos] < a[i]) {
			int temp = a[i];
			a[i] = a[min_pos];
			a[min_pos] = temp;
		}
	}
}

// INSERTION SORT
void InsertionSort(int a[], int n) {
	for (int i = 0; i < n; i++) {
		int j = i;
		while (j > 0 && a[j] < a[j - 1]) {
			swap(a[j], a[j - 1]);
			j--;
		}
	}
}

// BUBBLE SORT
void BubbleSort(int a[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (a[j] > a[i]) {
				swap(a[i], a[j]);
			}
		}
	}
}

// SHELL SORT
void ShellSort(int arr[], int n)
{
	// Start with a big gap, then reduce the gap
	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < n; i += 1)
		{
			int temp = arr[i];

			int j;
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
				arr[j] = arr[j - gap];

			arr[j] = temp;
		}
	}
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
		Heapify(a, n, parent);
	}
}

void HeapSort(int a[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--) {
		Heapify(a, n, i);
	}
	for (int i = n - 1; i > 0; i--) {
		swap(a[i], a[0]);
		Heapify(a, i, 0);
	}
}

// MERGE SORT
void Merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* Tạo các mảng tạm */
	//int L[100], R[100];
	auto* L = new int[125000], * R = new int[125000];

	/* Copy dữ liệu sang các mảng tạm */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	/* Gộp hai mảng tạm vừa rồi vào mảng arr*/
	i = 0; // Khởi tạo chỉ số bắt đầu của mảng con đầu tiên
	j = 0; // Khởi tạo chỉ số bắt đầu của mảng con thứ hai
	k = l; // IKhởi tạo chỉ số bắt đầu của mảng lưu kết quả
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy các phần tử còn lại của mảng L vào arr nếu có */
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy các phần tử còn lại của mảng R vào arr nếu có */
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
	delete[] L;
	delete[] R;
}

void MergeSort(int a[], int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;
		MergeSort(a, left, mid);
		MergeSort(a, mid + 1, right);
		Merge(a, left, mid, right);
	}
}

// QUICK SORT
void QuickSort(int arr[], int left, int right) {
	int pivot = left + (right - left) / 2;
	int i = left;
	int j = right;
	while (i < j) {
		while (arr[i] < arr[pivot])
			i++;
		while (arr[j] > arr[pivot])
			j--;
		if (i <= j) {
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}
	if (i < right)
		QuickSort(arr, i, right);
	if (left < j)
		QuickSort(arr, left, j);
}

// RADIX SORT
void RadixSort(int* a, int n)
{
	int i, m = a[0], exp = 1;
	auto* b = new int[250000];
	for (i = 0; i < n; i++)
	{
		if (a[i] > m)
			m = a[i];
	}
	while (m / exp > 0)
	{
		int bucket[10] = { 0 };
		for (i = 0; i < n; i++)
			bucket[a[i] / exp % 10]++;
		for (i = 1; i < 10; i++)
			bucket[i] += bucket[i - 1];
		for (i = n - 1; i >= 0; i--)
			b[--bucket[a[i] / exp % 10]] = a[i];
		for (i = 0; i < n; i++)
			a[i] = b[i];
		exp *= 10;
	}
	delete[] b;
}

////////////////////// END OF SORT ALGORITHM //////////////////////
//DATA GENERATOR
void HoanVi(int& a, int& b)
{
	int x = a;
	a = b;
	b = x;
}
//-------------------------------------------------

// Hàm phát sinh mảng dữ liệu ngẫu nhiên
void GenerateRandomData(int a[], int n)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % n;
	}
}

// Hàm phát sinh mảng dữ liệu có thứ tự tăng dần
void GenerateSortedData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
}

// Hàm phát sinh mảng dữ liệu có thứ tự ngược (giảm dần)
void GenerateReverseData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = n - 1 - i;
	}
}

// Hàm phát sinh mảng dữ liệu gần như có thứ tự
void GenerateNearlySortedData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 10; i++)
	{
		int r1 = rand() % n;
		int r2 = rand() % n;
		HoanVi(a[r1], a[r2]);
	}
}

void GenerateData(int a[], int n, int dataType)
{
	switch (dataType)
	{
	case 0:	// ngẫu nhiên
		GenerateRandomData(a, n);
		break;
	case 1:	// có thứ tự
		GenerateSortedData(a, n);
		break;
	case 2:	// có thứ tự ngược
		GenerateReverseData(a, n);
		break;
	case 3:	// gần như có thứ tự
		GenerateNearlySortedData(a, n);
		break;
	default:
		printf("Error: unknown data type!\n");
	}
}

// END
//////////////////////////////////////////////////////////////////

int main() {
	int a[251000];
	int key = 0;
	cout << "Input key: " << endl;
	cout << "key = 1: Selection Sort" << endl;
	cout << "key = 2: Insertion Sort" << endl;
	cout << "key = 3: Bubble Sort" << endl;
	cout << "key = 4: Shell Sort" << endl;
	cout << "key = 5: Heap Sort" << endl;
	cout << "key = 6: Merge Sort" << endl;
	cout << "key = 7: Quick Sort" << endl;
	cout << "key = 8: Radix Sort" << endl;
	cin >> key;
	while (true) {
		if (key == 1) {
			int n = 0;
			cout << "Welcome to Selection Sort :) " << endl;
			cout << "Input n: " << endl;
			cin >> n;
			GenerateData(a, n, 0);
			clock_t start, end;
			start = clock();
			SelectionSort(a, n);
			end = clock();
			double time_use = (double)(end - start) / CLOCKS_PER_SEC;
			cout << "With n = " << n << " and random data, time use is : " << time_use << endl;

			GenerateData(a, n, 1);
			start = clock();
			SelectionSort(a, n);
			end = clock();
			time_use = (double)(end - start) / CLOCKS_PER_SEC;
			cout << "With n = " << n << " and sorted data, time use is : " << time_use << endl;

			GenerateData(a, n, 2);
			start = clock();
			SelectionSort(a, n);
			end = clock();
			time_use = (double)(end - start) / CLOCKS_PER_SEC;
			cout << "With n = " << n << " and reverse data, time use is : " << time_use << endl;

			GenerateData(a, n, 3);
			start = clock();
			SelectionSort(a, n);
			end = clock();
			time_use = (double)(end - start) / CLOCKS_PER_SEC;
			cout << "With n = " << n << " and nearly sorted data, time use is : " << time_use << endl;
		}
		if (key == 2) {
			int n = 0;
			cout << "Welcome to Insertion Sort :) " << endl;
			cout << "Input n: " << endl;
			cin >> n;
			GenerateData(a, n, 0);
			clock_t start, end;
			start = clock();
			InsertionSort(a, n);
			end = clock();
			double time_use = (double)(end - start) / CLOCKS_PER_SEC;
			cout << "With n = " << n << " and random data, time use is : " << time_use << endl;

			GenerateData(a, n, 1);
			start = clock();
			InsertionSort(a, n);
			end = clock();
			time_use = (double)(end - start) / CLOCKS_PER_SEC;
			cout << "With n = " << n << " and sorted data, time use is : " << time_use << endl;

			GenerateData(a, n, 2);
			start = clock();
			InsertionSort(a, n);
			end = clock();
			time_use = (double)(end - start) / CLOCKS_PER_SEC;
			cout << "With n = " << n << " and reverse data, time use is : " << time_use << endl;

			GenerateData(a, n, 3);
			start = clock();
			InsertionSort(a, n);
			end = clock();
			time_use = (double)(end - start) / CLOCKS_PER_SEC;
			cout << "With n = " << n << " and nearly sorted data, time use is : " << time_use << endl;
		}
		if (key == 3) {
			int n = 0;
			cout << "Welcome to Bubble Sort :) " << endl;
			cout << "Input n: " << endl;
			cin >> n;
			GenerateData(a, n, 0);
			clock_t start, end;
			start = clock();
			BubbleSort(a, n);
			end = clock();
			double time_use = (double)(end - start) / CLOCKS_PER_SEC;
			cout << "With n = " << n << " and random data, time use is : " << time_use << endl;

			GenerateData(a, n, 1);
			start = clock();
			BubbleSort(a, n);
			end = clock();
			time_use = (double)(end - start) / CLOCKS_PER_SEC;
			cout << "With n = " << n << " and sorted data, time use is : " << time_use << endl;

			GenerateData(a, n, 2);
			start = clock();
			BubbleSort(a, n);
			end = clock();
			time_use = (double)(end - start) / CLOCKS_PER_SEC;
			cout << "With n = " << n << " and reverse data, time use is : " << time_use << endl;

			GenerateData(a, n, 3);
			start = clock();
			BubbleSort(a, n);
			end = clock();
			time_use = (double)(end - start) / CLOCKS_PER_SEC;
			cout << "With n = " << n << " and nearly sorted data, time use is : " << time_use << endl;
		}
		if (key == 4) {
			int n = 0;
			cout << "Welcome to Shell Sort :) " << endl;
			cout << "Input n: " << endl;
			cin >> n;
			GenerateData(a, n, 0);
			clock_t start, end;
			start = clock();
			ShellSort(a, n);
			end = clock();
			double time_use = (double)(end - start) / CLOCKS_PER_SEC;
			cout << "With n = " << n << " and random data, time use is : " << time_use << endl;

			GenerateData(a, n, 1);
			start = clock();
			ShellSort(a, n);
			end = clock();
			time_use = (double)(end - start) / CLOCKS_PER_SEC;
			cout << "With n = " << n << " and sorted data, time use is : " << time_use << endl;

			GenerateData(a, n, 2);
			start = clock();
			ShellSort(a, n);
			end = clock();
			time_use = (double)(end - start) / CLOCKS_PER_SEC;
			cout << "With n = " << n << " and reverse data, time use is : " << time_use << endl;

			GenerateData(a, n, 3);
			start = clock();
			ShellSort(a, n);
			end = clock();
			time_use = (double)(end - start) / CLOCKS_PER_SEC;
			cout << "With n = " << n << " and nearly sorted data, time use is : " << time_use << endl;
		}
		if (key == 5) {
			int n = 0;
			cout << "Welcome to Heap Sort :) " << endl;
			cout << "Input n: " << endl;
			cin >> n;
			GenerateData(a, n, 0);
			clock_t start, end;
			start = clock();
			HeapSort(a, n);
			end = clock();
			double time_use = (double)(end - start) / CLOCKS_PER_SEC;
			cout << "With n = " << n << " and random data, time use is : " << time_use << endl;

			GenerateData(a, n, 1);
			start = clock();
			HeapSort(a, n);
			end = clock();
			time_use = (double)(end - start) / CLOCKS_PER_SEC;
			cout << "With n = " << n << " and sorted data, time use is : " << time_use << endl;

			GenerateData(a, n, 2);
			start = clock();
			HeapSort(a, n);
			end = clock();
			time_use = (double)(end - start) / CLOCKS_PER_SEC;
			cout << "With n = " << n << " and reverse data, time use is : " << time_use << endl;

			GenerateData(a, n, 3);
			start = clock();
			HeapSort(a, n);
			end = clock();
			time_use = (double)(end - start) / CLOCKS_PER_SEC;
			cout << "With n = " << n << " and nearly sorted data, time use is : " << time_use << endl;
		}
		if (key == 6) {
			int n = 0;
			cout << "Welcome to Merge Sort :) " << endl;
			cout << "Input n: " << endl;
			cin >> n;
			GenerateData(a, n, 0);
			clock_t start, end;
			start = clock();
			MergeSort(a, 0, n-1);
			end = clock();
			double time_use = (double)(end - start) / CLOCKS_PER_SEC;
			cout << "With n = " << n << " and random data, time use is : " << time_use << endl;

			GenerateData(a, n, 1);
			start = clock();
			MergeSort(a, 0, n - 1);
			end = clock();
			time_use = (double)(end - start) / CLOCKS_PER_SEC;
			cout << "With n = " << n << " and sorted data, time use is : " << time_use << endl;

			GenerateData(a, n, 2);
			start = clock();
			MergeSort(a, 0, n - 1);
			end = clock();
			time_use = (double)(end - start) / CLOCKS_PER_SEC;
			cout << "With n = " << n << " and reverse data, time use is : " << time_use << endl;

			GenerateData(a, n, 3);
			start = clock();
			MergeSort(a, 0, n - 1);
			end = clock();
			time_use = (double)(end - start) / CLOCKS_PER_SEC;
			cout << "With n = " << n << " and nearly sorted data, time use is : " << time_use << endl;
		}
		if (key == 7) {
			int n = 0;
			cout << "Welcome to Quick Sort :) " << endl;
			cout << "Input n: " << endl;
			cin >> n;
			GenerateData(a, n, 0);
			clock_t start, end;
			start = clock();
			QuickSort(a, 0, n - 1);
			end = clock();
			double time_use = (double)(end - start) / CLOCKS_PER_SEC;
			cout << "With n = " << n << " and random data, time use is : " << time_use << endl;

			GenerateData(a, n, 1);
			start = clock();
			QuickSort(a, 0, n - 1);
			end = clock();
			time_use = (double)(end - start) / CLOCKS_PER_SEC;
			cout << "With n = " << n << " and sorted data, time use is : " << time_use << endl;

			GenerateData(a, n, 2);
			start = clock();
			QuickSort(a, 0, n - 1);
			end = clock();
			time_use = (double)(end - start) / CLOCKS_PER_SEC;
			cout << "With n = " << n << " and reverse data, time use is : " << time_use << endl;

			GenerateData(a, n, 3);
			start = clock();
			QuickSort(a, 0, n - 1);
			end = clock();
			time_use = (double)(end - start) / CLOCKS_PER_SEC;
			cout << "With n = " << n << " and nearly sorted data, time use is : " << time_use << endl;
		}
		if (key == 8) {
			int n = 0;
			cout << "Welcome to Radix Sort :) " << endl;
			cout << "Input n: " << endl;
			cin >> n;
			GenerateData(a, n, 0);
			clock_t start, end;
			start = clock();
			RadixSort(a, n);
			end = clock();
			double time_use = (double)(end - start) / CLOCKS_PER_SEC;
			cout << "With n = " << n << " and random data, time use is : " << time_use << endl;

			GenerateData(a, n, 1);
			start = clock();
			RadixSort(a, n);
			end = clock();
			time_use = (double)(end - start) / CLOCKS_PER_SEC;
			cout << "With n = " << n << " and sorted data, time use is : " << time_use << endl;

			GenerateData(a, n, 2);
			start = clock();
			RadixSort(a, n);
			end = clock();
			time_use = (double)(end - start) / CLOCKS_PER_SEC;
			cout << "With n = " << n << " and reverse data, time use is : " << time_use << endl;

			GenerateData(a, n, 3);
			start = clock();
			RadixSort(a, n);
			end = clock();
			time_use = (double)(end - start) / CLOCKS_PER_SEC;
			cout << "With n = " << n << " and nearly sorted data, time use is : " << time_use << endl;
		}
		cout << endl << "Input key: " << endl;
		cin >> key;
		if (key == 0) {
			break;
		}
	}
	return 0;
}