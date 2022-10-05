#include <iostream>
using namespace std;

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

int main() {
	int a[100];
	int n = 0;
	cout << "Input n: " << endl;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Input a[" << i << "]" << endl;
		cin >> a[i];
	}
	SelectionSort(a, n);
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	return 0;
}