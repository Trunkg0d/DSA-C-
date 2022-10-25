#include<iostream>
using namespace std;

// 2/2 = 1, 1/2 = 0
int DecToBinR(int dec){
    if(dec==0){
        return NULL;
    } else {
        DecToBinR(dec/2);
    }
    cout << dec%2;
}

int main(){
    DecToBinR(2);
    return 0;
}