#include<iostream>
using namespace std;

int main(){
  int a[100000];
  int n;
  cout << "Input number of elements: ";
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  for(int i = 0; i < n; i++){
    cout << a[i] << " ";
  }

  int check[100000];
  int check_len = 1;
  check[0] = a[0];

  for(int i = 1; i < n; i++){
    int flag = 0;
    for(int j = 0; j < check_len; j++){
      if(a[i] == check[j]){
        flag = 1;
      }
    }
    if(flag == 0){
      check[check_len] = a[i];
      check_len++;
    }
  }

  // Output to check
  cout << endl;
  for(int i = 0; i < check_len; i++){
    cout << check[i] << " ";
  }
  cout << endl << check_len << endl;
  return 0;
}