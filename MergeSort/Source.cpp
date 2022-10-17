#include <iostream>
using namespace std;

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

void mergeSort(int a[], int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;
		mergeSort(a, left, mid);
		mergeSort(a, mid + 1, right);
		Merge(a, left, mid, right);
	}
}

void inputArray(int a[100], int& n) {
    cout << "Input n: " << endl;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

void outputArray(int a[100], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}


int main() {
    int a[100];
    int n;
    inputArray(a, n);
    outputArray(a, n);
    cout << endl;
    mergeSort(a, 0, n - 1);
    outputArray(a, n);
    return 0;
}