#include<iostream>
#include<string>
#include<fstream>
using namespace std;

string cutName(string s) {
    string temp = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != ' ') {
            temp += s[i];
        }
        else {
            temp = "";
        }
    }
    return temp;
}

int main(){
    if(cutName("Vo Thu Trang") > cutName("Le Pham Hoang Trung")){
        cout << 1 << endl;
    } else {
        cout << 2 << endl;
    }

    if(cutName("Le Pham Hoang Trung") > cutName("Vo Thu Trang")){
        cout << 1 << endl;
    } else {
        cout << 2 << endl;
    }
    return 0;
}