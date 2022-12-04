#include <iostream>
#include <string>
#include "dirent.h"
#include <vector>
#include <math.h>
#include <cstdio>
#include <filesystem>

using namespace std;
#define SIZE 200

string printSymbol(string pathInput, string path)
{

    string print = "";
    path = path.substr(0, path.rfind("/"));

    if (path.compare(pathInput) == 0)
    {
        return print;
    }

    unsigned long index = path.rfind("/");
    path = path.substr(0, index);
    print = "|_  " + print;

    while (path.compare(pathInput) != 0)
    {
        unsigned long index = path.rfind("/");
        path = path.substr(0, index);
        print = "    " + print;
    }

    return print;
}

void readData(string path, vector<string> &data, vector<string> &dataFile)
{

    char s[205];
    strcpy(s, path.c_str());

    DIR *directory = opendir(s);
    struct dirent *entry;

    if (directory == NULL)
    {
        cout << "Not found directory" << endl;
        return;
    }

    string tempPath;
    while (((entry = readdir(directory))))
    {

        if (entry->d_type == DT_REG && (entry->d_name[0] != '.'))
        {
            data.push_back(path + "/" + entry->d_name);
            dataFile.push_back(path + "/" + entry->d_name);
        }

        if (entry->d_type == DT_DIR && (entry->d_name[0] != '.'))
        {
            tempPath = path + "/" + entry->d_name;
            data.push_back(tempPath);
            readData(tempPath, data, dataFile);

            tempPath = path;
        }
    }
}

void function1(string pathInput, vector<string> data)
{

    for (int i = 0; i < data.size(); i++)
    {
        cout << printSymbol(pathInput, data[i]) << data[i].substr(data[i].rfind("/") + 1);
        cout << endl;
    }
}

long long specialPow(long long i)
{
    long long res = 1; // Initialize result
    long long m = pow(10, 9) + 9;
    long long p = 31;
    // Update p if it is more than or equal to m
    p = p % m;

    while (i > 0)
    {
        // If i is odd, multiply p with the result
        if (i & 1)
            res = (res * p) % m;
        // i must be even now
        i = i >> 1; // i = i/2
        p = (p * p) % m;
    }
    return res;
}

long long hashString(string file_name)
{
    string cut = "";
    if (file_name.length() <= 20)
    {
        cut = file_name;
    }
    else
    {
        for (int i = file_name.length() - 20; i < file_name.length(); i++)
        {
            cut += file_name[i];
        }
    }
    long long res = 0;
    long long before = 0;
    long long m = (pow(10, 9) + 9);
    before = ((cut[0] % m) * specialPow(0)) % m;
    for (int i = 1; i < cut.length(); i++)
    {
        long long temp = (long long)(cut[i] % m) * specialPow(i);
        before = (before % m + temp) % m;
    }
    return before;
}

struct NODE
{
    string filePath;
    NODE *p_next;
};

NODE *createNode(string filePath)
{
    NODE *p = new NODE;
    p->filePath = filePath;
    p->p_next = NULL;
    return p;
}

NODE **createHashTable(vector<string> data)
{
    NODE **hashTable = new NODE *[SIZE];
    for (int i = 0; i < SIZE; ++i)
        hashTable[i] = NULL;

    for (int i = 0; i < data.size(); i++)
    {
        string fileName = data[i].substr(data[i].rfind("/") + 1);

        long long index = hashString(fileName) % SIZE;

        if (hashTable[index] == NULL)
        {
            hashTable[index] = createNode(data[i]);
        }
        else
        {
            NODE *p = hashTable[index];

            while (p->p_next != NULL)
            {
                p = p->p_next;
            }

            p->p_next = createNode(data[i]);
        }
    }
    return hashTable;
}

void Search(NODE **hashTable, string fileName)
{
    long long index = hashString(fileName) % SIZE;

    if (hashTable[index] == NULL)
    {
        cout << "Not found" << endl;
        return;
    }

    NODE *p = hashTable[index];

    while (p != NULL)
    {
        string path = p->filePath;
        string name = path.substr(path.rfind("/") + 1);

        if (name == fileName)
        {
            cout << p->filePath << endl;
        }
        p = p->p_next;
    }

    return;
}

void moveFile(string filePath, string destination)
{
    rename(filePath.c_str(), destination.c_str());
    return;
}

void deleteFolder(string path)
{
    filesystem::remove(path);
    return;
}

string getLowercase(string path)
{
    string tmp = path.substr(path.rfind('/') + 1);
    string res = "";
    int i = 0;
    while (i < tmp.length() && tmp[i] != '.')
    {
        char c = tmp[i++];
        if ('A' <= c && c <= 'Z')
            c = c + 'a' - 'A';
        res = res + c;
    }
    return res;
}

void createLowercaseVector(vector<string> a, vector<string> &lowercase)
{
    for (int i = 0; i < a.size(); ++i)
        lowercase.push_back(getLowercase(a[i]));
    return;
}

void merge(vector<string> &a, vector<string> &lowerCase, int l, int m, int r)
{
    int i = l, j = m + 1;
    string tmp1[20005];
    string tmp2[20005];
    for (int k = l; k <= r; ++k)
    {
        if (i > m)
        {
            tmp1[k] = a[j];
            tmp2[k] = lowerCase[j++];
        }
        else if (j > r)
        {
            tmp1[k] = a[i];
            tmp2[k] = lowerCase[i++];
        }
        else if (lowerCase[i] < lowerCase[j])
        {
            tmp1[k] = a[i];
            tmp2[k] = lowerCase[i++];
        }
        else
        {
            tmp1[k] = a[j];
            tmp2[k] = lowerCase[j++];
        }
    }
    for (int k = l; k <= r; ++k)
    {
        a[k] = tmp1[k];
        lowerCase[k] = tmp2[k];
    }
    return;
}

void mergeSort(vector<string> &a, vector<string> &lowercase, int l, int r)
{
    if (l >= r)
        return;
    for (int i = l; i < r; ++i)
        if (lowercase[i] > lowercase[i + 1])
        {
            int m = (l + r) / 2;
            mergeSort(a, lowercase, l, m);
            mergeSort(a, lowercase, m + 1, r);
            merge(a, lowercase, l, m, r);
            break;
        }
    return;
    // a: aBcdEf, hiHI | lowercase: abcdef, hihi
    // lowercase array is needed to improve performance
}

void deleteEmptyFolders(string path)
{
    vector<string> emptyPath;

    char s[205];
    strcpy(s, path.c_str());

    DIR *directory = opendir(s);
    struct dirent *entry;

    string tempPath;
    while (((entry = readdir(directory))))
    {
        if (entry->d_type == DT_DIR && (entry->d_name[0] != '.'))
        {
            tempPath = path + "/" + entry->d_name;
            if (strcmp(entry->d_name, "OrderedFolder"))
                emptyPath.push_back(tempPath);
        } // find remaining subfolders
    }
    for (int i = 0; i < emptyPath.size(); ++i)
        filesystem::remove_all(emptyPath[i]);
    return;
}

string createDirectory(string s, string path)
{
    string tmp = "";
    path = path + "/OrderedFolder/";
    for (int i = 0; i < s.length(); ++i)
    {
        tmp = tmp + s[i];
        path = path + tmp + '/';
    }
    filesystem::create_directories(path);
    return path;
    // s: ABC, path (before): D:/HAHA
    // path (after): D://HAHA/A/AB/ABC/
}

void renameFile(string &path, string &file, int num)
{
    string old = path;
    string cNum = to_string(num);
    int dot = path.find_last_of('.');
    path = path.substr(0, dot) + cNum + path.substr(dot, path.length() - 1);
    file = file + cNum;
    rename(old.c_str(), path.c_str());
    // path: D:/HAHA/tiki.taka -> D:/HAHA/tiki9.taka
    // file: tiki.taka -> tiki9.taka (num = 9)
}

void organize(string s, vector<string> d, vector<string> name, string currentPath)
{
    vector<string> hash[72];
    int len = s.length();
    bool check[36];
    // if s=ABC, check[25]=TRUE means there is a file named ABCZ.xyz

    for (int i = 0; i < d.size(); ++i)
    {
        // given a directory P->PB->PBC, pb.xyz must be in PB (not PBC)

        char c = name[i][len];
        // get i-th character of name

        int index = int(c - 'a');
        if ('0' <= c && c <= '9')
            index = int(c - '0') + 26;
        if ('A' <= c && c <= 'Z')
            index = int(c - 'A');
        // a = A = 0, b = B = 1,...z = Z = 25, '0'=26, '1'=27,...,'9'=35
        if (name[i].length() == len) // given a directory P->PB->PBC, pb.xyz must be in PB (not PBC)
        {
            check[index] = true;
            string destination = createDirectory(s, currentPath) + d[i].substr(d[i].rfind('/') + 1);
            moveFile(d[i], destination);
        }
        else
        {
            hash[index].push_back(d[i]);
            hash[index + 36].push_back(name[i]);
            // hash[1]: D:/HAHA/tiki.taka, hash[1+36]: tiki.taka
        }
    }

    for (int i = 0; i < 36; ++i)
    {
        char c = 'A' + i;
        if (i >= 26)
            c = '0' + i - 26;
        if (hash[i].size() > 3 || (hash[i].size() == 3 && check[i]))
            organize(s + c, hash[i], hash[i + 36], currentPath);
        else if (hash[i].size() > 0)
        {
            string path = createDirectory(s + c, currentPath);
            for (int j = 0; j < hash[i].size(); ++j)
            {
                string destination = path + hash[i][j].substr(hash[i][j].rfind('/') + 1);
                moveFile(hash[i][j], destination);
            }
        }
    }
}

void organizeFolder(string path)
{
    vector<string> all, filePath, fileName, tmp, fileNameLower;
    readData(path, all, filePath);
    // all: folder + files (D:/HAHA, D:/HAHA/tiki.taka)
    // filePath: files only (D:/tiki.taka)

    string s = "";
    for (int i = 0; i < filePath.size(); ++i)
    {
        string file = filePath[i].substr(filePath[i].rfind('/') + 1);
        string name = file.substr(0, file.find_last_of('.'));
        fileName.push_back(name);
        fileNameLower.push_back(getLowercase(name));
    }
    // filePath: D:/HAHA/TiKi.taka
    // fileName: TiKi.taka
    // fileNameLower: tiki.taka

    tmp = fileNameLower;
    mergeSort(filePath, fileNameLower, 0, filePath.size() - 1);
    fileNameLower = tmp;
    mergeSort(fileName, fileNameLower, 0, filePath.size() - 1);

    string prev = fileName[0];
    int cnt = 1;
    for (int i = 1; i < fileName.size(); ++i)
    {
        if (fileName[i] == prev)
        {
            ++cnt;
            if (cnt == 2)
                renameFile(filePath[i - 1], fileName[i - 1], 1);
            renameFile(filePath[i], fileName[i], cnt);
        }
        else
        {
            cnt = 1;
            prev = fileName[i];
        }
    }
    // add sequence number if there is duplication

    organize(s, filePath, fileName, path);
    deleteEmptyFolders(path);

    all.clear();
    filePath.clear();

    readData(path, all, filePath); // read current directory after the changes
    function1(path, all);          // print current directory

    return;
}

int main()
{
    string pathInput = "D:/COLLEGE/COMP";
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

    do
    {
        cout << endl;
        cout << "Nhap so thu tu cua chuc nang: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << endl;
            function1(pathInput, data);
        }

        if (choice == 2)
        {
            cout << "Chuc nang 2" << endl;
            string fileName;
            cout << "File name: ";
            cin >> fileName;

            NODE **hashTable = createHashTable(data);
            Search(hashTable, fileName);
        }

        if (choice == 3)
        {
            cout << "Chuc nang 3" << endl;
            string filePath;
            cout << "Enter path: ";
            getline(cin, filePath);
            getline(cin, filePath);
            organizeFolder(filePath);
        }

        if (choice == 0)
        {
            return 0;
        }

    } while (choice > 0 && choice <= 3);

    return 0;
}
