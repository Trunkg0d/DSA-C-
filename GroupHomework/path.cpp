#include<iostream>
#include<string>
#include "dirent.h"
#include<vector>
#include<math.h>

using namespace std;
#define SIZE 200

string printSymbol(string pathInput, string path) {
    /*
     In "|_  " để phân biệt các file con
     
     string pathInput -- đường dẫn thư mục ban đầu nhập vào để đọc
     string path -- đường dẫn của file/ thư mục cần in ra
     */
    
    string print = "";
    path = path.substr(0, path.rfind("/"));
    
    if (path.compare(pathInput) == 0) {
        return print;
    }
    
    unsigned long index = path.rfind("/");
    path = path.substr(0, index);
    print = "|_  " + print;
    
    while (path.compare(pathInput) != 0) {
        unsigned long index = path.rfind("/");
        path = path.substr(0, index);
        print = "    " + print;
    }

    return print;
}

void readData(string path, vector<string> &data, vector<string> &dataFile) {
    /*
     Đọc các file/ thư mục trong đường dẫn path
     
     string path -- đường dẫn thư mục cha, gọi trong hàm main sẽ là đường dẫn nhập vào
     
     vector<string> &data -- vector chứa dữ liệu là đường dẫn của các file/ thư mục đọc được
     (VD: data[0] = "/Users/thutrang/Documents/RStudio/Tuan1.R")
     
     vector<string> &dataFile -- vector chứa dữ liệu là đường dẫn của các file đọc được
     */
    
    char s[path.length() + 1];
    strcpy(s, path.c_str());

    DIR* directory = opendir(s);
    struct dirent *entry;

    if (directory == NULL) {
        cout << "Not found directory" << endl;
        return;
    }
    
    string tempPath;
    while (((entry = readdir(directory)))) {

        if (entry->d_type == DT_REG && (entry->d_name[0] != '.')) {
            data.push_back(path + "/" + entry->d_name);
            dataFile.push_back(path + "/" + entry->d_name);
        }

        if (entry->d_type == DT_DIR && (entry->d_name[0] != '.')) {
            tempPath = path + "/" + entry->d_name;
            data.push_back(tempPath);
            readData(tempPath, data, dataFile);
            
            tempPath = path;
        }

    }
}

void function1(string pathInput, vector<string> data) {
    /*
     Thực hiện chức năng 1, in ra màn hình toàn bộ tập tin và thư mục con trong thư mục nhập vào
     
     string pathInput -- đường dẫn thư mục nhập vào
     vector<string> data -- chứa các dữ liệu đã đọc trong hàm readData()
     */
    
    for (int i = 0; i < data.size(); i++) {
        cout << printSymbol(pathInput, data[i]) << data[i].substr(data[i].rfind("/") + 1);
        cout << endl;
    }
}

//int hashString(string fileName) {
//    int sumCharacter = 0;
//    for (int i = 0; i < fileName.length(); i++) {
//        sumCharacter += fileName[i];
//    }
//    return (sumCharacter - 'a');
//}

long long specialPow(long long i)
{
    long long res = 1; // Initialize result
    long long m = pow(10, 9) + 9;
    long long p =31;
    // Update p if it is more than or equal to m
    p = p % m;
 
    while (i > 0) {
        // If i is odd, multiply p with the result
        if (i & 1)
            res = (res * p) % m;
        // i must be even now
        i = i >> 1; // i = i/2
        p = (p * p) % m;
    }
    return res;
}

long long hashString(string file_name) {
    string cut = "";
    if (file_name.length() <= 20) {
        cut = file_name;
    }
    else {
        for (int i = file_name.length() - 20; i < file_name.length(); i++) {
            cut += file_name[i];
        }
    }
    long long res = 0;
    long long before = 0;
    long long m = (pow(10, 9) + 9);
    before = ((cut[0]%m) * specialPow(0))%m;
    for (int i = 1; i < cut.length(); i++) {
        long long temp = (long long)(cut[i]%m) * specialPow(i);
        before = (before%m + temp) % m;
    }
    return before;
}

struct NODE {
    string filePath;
    NODE* p_next;
};

NODE* createNode(string filePath) {
    NODE* p = new NODE;
    p->filePath = filePath;
    p->p_next = NULL;
    return p;
}

NODE** createHashTable(vector<string> data) {
    NODE** hashTable = new NODE*[SIZE];
    for (int i = 0; i < 50; i++) {
        hashTable[i] = NULL;
    }

    for (int i = 0; i < data.size(); i++) {
        string fileName = data[i].substr(data[i].rfind("/") + 1);
        
        long long index = hashString(fileName) % SIZE;

        if (hashTable[index] == NULL) {
            hashTable[index] = createNode(data[i]);
        } else {
            NODE* p = hashTable[index];

            while (p->p_next != NULL) {
                p = p->p_next;
            }

            p->p_next = createNode(data[i]);
        }

        
    }

    return hashTable;
}

void Search(NODE** hashTable, string fileName) {
    long long index = hashString(fileName) % SIZE;

    if (hashTable[index] == NULL) {
        cout << "Not found" << endl;
        return;
    }

    NODE* p = hashTable[index];

    while (p != NULL) {
        string path = p->filePath;
        string name = path.substr(path.rfind("/") + 1);
        
        if (name == fileName) {
            cout << p->filePath << endl;
        }
        p = p->p_next;
    }
    
    return;
}

int main () {
    string pathInput = "D:/D Data/code/C++/DSA";
//    cout << "pathInput: ";
//    getline(cin, pathInput);
    
    vector<string> data;
    vector<string> dataFile;
    readData(pathInput, data, dataFile);
        
    int choice;
    cout << "1. Chuc nang 1" << endl;
    cout << "2. Chuc nang 2" << endl;
    cout << "3. Chuc nang 3" << endl;
    cout << "0. Dung chuong trinh" << endl;

    do {
        cout << endl;
        cout << "Nhap so thu tu cua chuc nang: ";
        cin >> choice;

        if (choice == 1) {
            cout << endl;
            function1(pathInput, data);
        }

        if (choice == 2) {
            cout << "Chuc nang 2" << endl;
            string fileName;
            cout << "File name: ";
            cin >> fileName;

            NODE** hashTable = createHashTable(data);
            Search(hashTable, fileName);


        }

        if (choice == 3) {
            cout << "Chuc nang 3" << endl;

        }

        if (choice == 0) {
            return 0;
        }

    } while (choice > 0 && choice <= 3);
    
    return 0;
}
