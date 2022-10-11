#include <iostream>
using namespace std;

int main() {
	//Cú pháp: <con_trỏ> = new <kiểu>
	int* p = new int;

	//Cấp phát một mảng vùng nhớ liên tục cho con trỏ quản lý
	//Cú pháp: <con_trỏ> = new <kiểu>[kích_thước]
	int* pArr = new int[100];

	// Huỷ vùng nhớ đã cấp phát cho con trỏ
	delete p;

	//Huy mảng vùng nhớ đã cấp phát cho con trỏ
	delete[]pArr;

	//Truy xuất nội dung của vùng nhớ do con trỏ quản lý
	int* p1 = new int;
	*p1 = 5;
	cout << "*p1: " <<  * p1 << endl;
	*p1 = *p1 + 10;

	//Chỉ định vùng nhớ do con trỏ quản lý
	int* p2, x = 10;
	p2 = &x;
	cout << "*p2: " <<  * p2 << endl;
	*p2 += 1;
	cout << "*p2: " <<  * p2 << endl;
	cout << "x: " << x << endl;
}