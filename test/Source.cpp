#include <iostream>
using namespace std;



int main() {
	int* a = new int[1];
	a[0] = 1;
	a[1] = 2;
	a[2] = 3;
	for (int i = 0; i < 3; i++) {
		cout << a[i] << " ";
	}
	return 0;
}