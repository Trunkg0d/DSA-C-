#include<iostream>
using namespace std;

void merge(int a[], int left, int mid, int right){
    int i, j, k;
    int n1 = mid-left +1;
    int n2 = right-mid;
    int L[100], R[100];

    for(int i=0;i<n1;i++){
        L[i] = a[left+i];
    }

    for(int i=0;i<n2;i++){
        R[i] = a[mid+1+i];
    }
    i=0;
    j=0;
    k=left;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        a[k] = L[i];
        i++;
        k++;
    }
    while(j<n2){
        a[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int a[], int left, int right){
    if(left<right){
        int mid = left+(right-left)/2;
        mergeSort(a, left, mid);
        mergeSort(a, mid+1, right);
        merge(a, left, mid, right);
    }
}

void quickSort(int a[], int left, int right){
    int pivot = left + (right-left)/2;
    int i=left;
    int j=right;
    while(i<j){
        while(a[i]<a[pivot]){
            i++;
        }
        while(a[j]>a[pivot]){
            j--;
        }
        if(i<=j){
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if(i<right){
        quickSort(a, i, right);
    } 
    if(j>left){
        quickSort(a, j, left);
    }
}

int main(){
    int arr[] = { 9, 3, 4, 2, 1, 8 };
    int n=6;
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    mergeSort(arr, 0, n-1);
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}