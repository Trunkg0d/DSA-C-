#include <iostream>
using namespace std;

#define MAX 6

void printArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << "\t";
	cout << endl;
	cout << endl;
}

void RadixSort(int* a, int n)
{
	int b[MAX], m = a[0], exp = 1;

	for (int i = 0; i < n; i++)
		if (a[i] > m)
			m = a[i];

	while (m / exp > 0)
	{
		int bucket[10] = { 0 };
		for (int i = 0; i < n; i++)
			bucket[a[i] / exp % 10]++;
		cout << "Bucket is: ";
		printArray(bucket, 10);
		for (int i = 1; i < 10; i++)
			bucket[i] += bucket[i - 1];
		cout << "Bucket is: ";
		printArray(bucket, 10);
		for (int i = n - 1; i >= 0; i--)
			b[--bucket[a[i] / exp % 10]] = a[i];
		cout << "Bucket is: ";
		printArray(bucket, 10);
		cout << "b is: ";
		printArray(b, 6);
		for (int i = 0; i < n; i++)
			a[i] = b[i];
		cout << "a is: ";
		printArray(a, 6);
		cout << "b is: ";
		printArray(b, 6);
		exp *= 10;
	}
}

int main()
{
	int arr[MAX] = { 964, 354, 368, 128, 495, 121 };
	int i, n;

	cout << endl << "Before sort  : ";
	printArray(&arr[0], 6);

	RadixSort(&arr[0], 6);

	cout << endl << "After sort : ";
	printArray(&arr[0], 6);

	return 0;
}