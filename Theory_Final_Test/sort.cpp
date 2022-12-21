#include<iostream>
using namespace std;

void SelectionSort(int a[], int n){
  for(int i = 0; i < n; i++){
    int min_pos = i;
    for(int j = i + 1; j < n; j++){
      if(a[j] < a[min_pos]){
        min_pos = j;
      }
    }
    if(a[min_pos] < a[i]){
      swap(a[i], a[min_pos]);
    }
  }
}

void Heapify(int arr[], int n, int i){
  int parent = i;
  int left = 2*i + 1;
  int right = 2*i + 2;

  if(left < n && arr[left] > arr[parent]){
    parent = left;
  }
  if(right < n && arr[right] > arr[parent]){
    parent = right;
  }

  if(parent != i){
    swap(arr[parent], arr[i]);
    Heapify(arr, n, parent);
  }
}

void HeapSort(int arr[], int n){
  for(int i = n/2 - 1; i>=0; i--){
    Heapify(arr, n, i);
  }
  for(int i = n-1; i>= 0; i--){
    swap(arr[0], arr[i]);
    Heapify(arr, i, 0);
  }
}

void merge(int a[], int left, int mid, int right){
  int i, j, k;
  int n1 = mid - left + 1;
  int n2 = right - mid;
  int L[100], R[100];

  for(int i = 0; i < n1; i++){
    L[i] = a[left + i];
  }
  for(int i = 0; i < n2; i++){
    R[i] = a[right + 1 + i];
  }

  i = 0;
  j = 0;
  k = left;
  while(i < n1 && j < n2){
    if(L[i] < R[j]){
      a[k] = L[i];
      i++;
    }
    else{
      a[k] = R[j];
      j++;
    }
    k++;
  }
  while(i < n1){
    a[k] = L[i];
    i++;
    k++;
  }
  while(j < n2){
    a[k] = R[j];
    k++;
    j++;
  }
}

void MergeSort(int arr[], int left, int right){
  if(left < right){
    int mid = left + (right - left) / 2;
    MergeSort(arr, left, mid);
    MergeSort(arr, mid+1, right);
    merge(arr, left, mid, right);
  }
}

int main(){
  int a[8] = {64, 25, 12, 22, 11, 17, 5, 4};
  int n = 8;
  cout << "Before: ";
  for(int i = 0; i < n; i++){
    cout << a[i] << " ";
  }
  cout << endl;
  MergeSort(a, 0, 7);
  cout << "After: ";
  for(int i = 0; i < n; i++){
    cout << a[i] << " ";
  }
  return 0;
}