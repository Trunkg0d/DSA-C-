#include <iostream>
using namespace std;

void InsertionSort(int a[], int n) {
	for (int i = 1; i < n; i++) {
		int j = i;
		while (j > 0 && a[j] < a[j - 1]) {
			int temp = a[j - 1];
			a[j - 1] = a[j];
			a[j] = temp;
			j--;
		}
	}
}

int main() {
	int a[100];
	int n = 0;
	cout << "Input n: " << endl;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Input a[" << i << "]" << endl;
		cin >> a[i];
	}
	InsertionSort(a, n);
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	return 0;
}