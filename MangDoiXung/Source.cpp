#include <iostream>
using namespace std;

int mangdx(int* a, int n, int i) 
{
	if (i >= n - 1 - i) return 1;
	if (a[i] != a[n - 1 - i]) return 0;
	return mangdx(a, n, i + 1);
}

int main() {
	int a[100];
	int n = 6;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << mangdx(a, n, 0);
	return 0;
}