#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

void Swap(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}

void printArray(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

void assign(int x[], int y[], int n) {
	for (int i = 0; i < n; i++) {
		x[i] = y[i];
	}
}

//-------------------------------------------------------------------------------

// Cac thuat toan sap xep

void SelectionSort(int a[], int n) {
	for (int i = 0; i < (n - 1); i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j])
				swap(a[i], a[j]);
		}
	}
}

void InsertionSort(int a[], int n) {
	for (int i = 1; i < n; i++) {
		int tmp = a[i];
		int j = i - 1;
		while ((j >= 0) && (a[j] > tmp)) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = tmp;
	}
}

void BubbleSort(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = n - 1; j >= i + 1; j--) {
			if (a[j] < a[j - 1])
				Swap(a[j], a[j - 1]);
		}
	}
}

void ShellSort(int a[], int n) {
	int interval = n / 2;
	while (interval > 0) {
		for (int i = interval; i < n; i++) {
			int tmp = a[i];
			int j = i;
			while ((j >= interval) && (a[j - interval] > tmp)) {
				a[j] = a[j - interval];
				j = j - interval;
			}
			a[j] = tmp;
		}
		interval = interval / 2;
	}
}

/*
Ham parent tra ve nut cha cua nut i
Ham left tra ve nut con trai cua nut i
Ham right tra ve nut con phai cua nut i
*/
int parent(int i) {
	return i / 2;
}
int left(int i) {
	return 2 * i;
}
int right(int i) {
	return 2 * i + 1;
}

void heapify(int a[], int heapSize, int i) {
	int l = left(i);
	int r = right(i);
	int largest;
	if ((l <= heapSize) && (a[l] > a[i])) largest = l;
	else largest = i;
	if ((r <= heapSize) && (a[r] > a[largest])) largest = r;
	if (largest != i) {
		Swap(a[i], a[largest]);
		heapify(a, heapSize, largest);
	}
}

void buildHeap(int a[], int n) {
	for (int i = n / 2; i >= 0; i--) {
		heapify(a, n, i);
	}
}

void HeapSort(int a[], int n) {
	buildHeap(a, n);
	int heapSize = n - 1;
	for (int i = n - 1; i >= 1; i--) {
		Swap(a[0], a[i]);
		heapSize--;
		heapify(a, heapSize, 0);
	}
}
void merge(int a[], int n, int p, int q, int r) {
	int n1 = q - p + 1;
	int n2 = r - q;
	auto* L = new int[125000];
	auto* R = new int[125000];
	for (int i = 0; i < n1; i++)
		L[i] = a[p + i];
	for (int j = 0; j < n2; j++)
		R[j] = a[q + j + 1];
	int i = 0;
	int j = 0;
	for (int k = p; k <= r; k++) {
		if (L[i] <= R[j]) {
			a[k] = L[i];
			i++;
		}
		else {
			a[k] = R[j];
			j++;
		}
	}
	delete[] L;
	delete[] R;
}

void MergeSort(int a[], int n, int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		MergeSort(a, n, p, q);
		MergeSort(a, n, q + 1, r);
		merge(a, n, p, q, r);
	}
}

int partition(int a[], int p, int r) {
	int x = a[r];
	int i = p - 1;
	for (int j = p; j < r; j++) {
		if (a[j] <= x) {
			i++;
			Swap(a[i], a[j]);
		}
	}
	Swap(a[i + 1], a[r]);
	return (i + 1);
}

void QuickSort(int a[], int p, int r) {
	if (p < r) {
		int q = partition(a, p, r);
		QuickSort(a, p, q - 1);
		QuickSort(a, q + 1, r);
	}
}
int getMax(int a[], int n)
{
	int mx = a[0];
	for (int i = 1; i < n; i++)
		if (a[i] > mx)
			mx = a[i];
	return mx;
}

void countSort(int a[], int n, int exp)
{
	auto* output = new int[125000];
	int i, count[10] = { 0 };
	for (i = 0; i < n; i++)
		count[(a[i] / exp) % 10]++;
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (i = n - 1; i >= 0; i--) {
		output[count[(a[i] / exp) % 10] - 1] = a[i];
		count[(a[i] / exp) % 10]--;
	}
	for (i = 0; i < n; i++)
		a[i] = output[i];
	delete[] output;
}

void RadixSort(int a[], int n)
{
	int m = getMax(a, n);
	for (int exp = 1; m / exp > 0; exp *= 10)
		countSort(a, n, exp);
}


//---------------------------------------------------------------------------------------
//Sau day la phan cua cac ham sinh du lieu
void HoanVi(int& a, int& b)
{
	int x = a;
	a = b;
	b = x;
}

void GenerateRandomData(int a[], int n)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % n;
	}
}

void GenerateSortedData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
}

void GenerateReverseData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = n - 1 - i;
	}
}

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
	case 0:
		GenerateRandomData(a, n);
		break;
	case 1:
		GenerateSortedData(a, n);
		break;
	case 2:
		GenerateReverseData(a, n);
		break;
	case 3:
		GenerateNearlySortedData(a, n);
		break;
	default:
		printf("Error: unknown data type!\n");
	}
}

int main()
{
	int a[250000];
	int x[5] = { 2500, 10000, 25000, 100000, 250000 };
	for (int i = 0; i < 4; i++) {
		switch (i)
		{
		case 0:
			cout << "Sap xep ngau nhien: " << endl;
			break;
		case 1:
			cout << "Gan nhu co thu tu tang dan: " << endl;
			break;
		case 2:
			cout << "Co thu tu tang dan: " << endl;
			break;
		case 3:
			cout << "Thu tu nguoc (giam dan): " << endl;
			break;
		}
		for (int j = 0; j < 5; j++) {
			cout << "	Mang co kich thuoc " << x[j] << endl;
			//
			GenerateData(a, x[j], i);
			auto start = high_resolution_clock::now();
			SelectionSort(a, x[j]);
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<microseconds>(stop - start);
			cout << "		Selection sort " << duration.count() << " microseconds" << endl;
			//
			GenerateData(a, x[j], i);
			start = high_resolution_clock::now();
			InsertionSort(a, x[j]);
			stop = high_resolution_clock::now();
			duration = duration_cast<microseconds>(stop - start);
			cout << "		Insertion sort " << duration.count() << " microseconds" << endl;
			//
			GenerateData(a, x[j], i);
			start = high_resolution_clock::now();
			BubbleSort(a, x[j]);
			stop = high_resolution_clock::now();
			duration = duration_cast<microseconds>(stop - start);
			cout << "		Bubble sort " << duration.count() << " microseconds" << endl;
			//
			GenerateData(a, x[j], i);
			start = high_resolution_clock::now();
			ShellSort(a, x[j]);
			stop = high_resolution_clock::now();
			duration = duration_cast<microseconds>(stop - start);
			cout << "		Shell sort " << duration.count() << " microseconds" << endl;
			//
			GenerateData(a, x[j], i);
			start = high_resolution_clock::now();
			HeapSort(a, x[j]);
			stop = high_resolution_clock::now();
			duration = duration_cast<microseconds>(stop - start);
			cout << "		Heap sort " << duration.count() << " microseconds" << endl;
			//
			GenerateData(a, x[j], i);
			start = high_resolution_clock::now();
			MergeSort(a, x[j], 0, x[j] - 1);
			stop = high_resolution_clock::now();
			duration = duration_cast<microseconds>(stop - start);
			cout << "		Merge sort " << duration.count() << " microseconds" << endl;
			//
			GenerateData(a, x[j], i);
			start = high_resolution_clock::now();
			QuickSort(a, 0, x[j] - 1);
			stop = high_resolution_clock::now();
			duration = duration_cast<microseconds>(stop - start);
			cout << "		Quick sort " << duration.count() << " microseconds" << endl;
			//
			GenerateData(a, x[j], i);
			start = high_resolution_clock::now();
			RadixSort(a, x[j]);
			stop = high_resolution_clock::now();
			duration = duration_cast<microseconds>(stop - start);
			cout << "		Radix sort " << duration.count() << " microseconds" << endl;
		}
	}
	return 0;
}