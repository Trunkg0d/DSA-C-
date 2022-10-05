#include<iostream>
using namespace std;

void inputArray(int a[100][100], int& n, int& m) {
	cout << "Input n: " << endl;
	cin >> n;
	cout << "Input m: " << endl;
	cin >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << "Nhap phan tu a[" << i << "][" << j << "]: " << endl;
			cin >> a[i][j];
		}
	}
}

void outputArray(int a[100][100], int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	int a[100][100];
	int n, m;
	inputArray(a, n, m);
	outputArray(a, n, m);
	return 0;
}