#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <math.h>
#define ll long long int
using namespace std;

struct Company {
    string name;
    string profit_tax;
    string address;
};

Company readCompany(string line_info) {
    Company e;
    string temp = line_info;
    int pos = temp.find("|");
    e.name = temp.substr(0, pos);
    temp = temp.substr(pos + 1, temp.length() - pos);

    pos = temp.find("|");
    e.profit_tax = temp.substr(0, pos);
    temp = temp.substr(pos + 1, temp.length() - pos);

    pos = temp.find("|");
    e.address = temp.substr(0, pos);
    temp = temp.substr(pos + 1, temp.length() - pos);
    return e;
}

void outputCompany(Company c) {
    cout << "Name: " << c.name << endl;
    cout << "Profit tax: " << c.profit_tax << endl;
    cout << "Address: " << c.address << endl;
}

vector<Company> ReadCompanyList(string file_name) {
    fstream input;
    input.open(file_name, ios::in);
    vector<Company> vect;
    while (!input.eof()) {
        string line;
        getline(input, line);
        Company company = readCompany(line);
        vect.push_back(company);
    }
    return vect;
}

void outputCompanyList(vector<Company> vect) {
    for (int i = 0; i < vect.size(); i++) {
        outputCompany(vect[i]);
    }
}

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

long long HashString(string company_name) {
    string cut = "";
    if (company_name.length() <= 20) {
        cut = company_name;
    }
    else {
        for (int i = company_name.length() - 20; i < company_name.length(); i++) {
            cut += company_name[i];
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

struct CompanyNode {
    Company company;
    CompanyNode* p_next;
};

CompanyNode* createCompanyNode(Company com) {
    CompanyNode* node = new CompanyNode;
    node->company = com;
    node->p_next = NULL;
    return node;
}

CompanyNode** CreateHashTable(vector<Company> list_company) {
    CompanyNode** HashTable = new CompanyNode * [200];
    for (int i = 0; i < 200; i++) {
        HashTable[i] = NULL;
    }
    for (int i = 0; i < list_company.size(); i++) {
        CompanyNode* node = createCompanyNode(list_company[i]);
        int index = HashString(list_company[i].name) % 200;

        if (HashTable[index] == NULL) {
            HashTable[index] = node;
            continue;
        }
        else {
            CompanyNode* root = HashTable[index];
            while (root != NULL) {
                if (root->p_next == NULL) {
                    root->p_next = node;
                    break;
                }
                root = root->p_next;
            }
        }
    }
    return HashTable;
}

void Inset(CompanyNode** HashTable, Company company) {
    CompanyNode* node = createCompanyNode(company);
    long long index = HashString(company.name) % 200;
    if (HashTable[index] == NULL) {
        HashTable[index] = node;
    }
    else {
        CompanyNode* root = HashTable[index];
        while (root != NULL) {
            if (root->p_next == NULL) {
                root->p_next = node;
                break;
            }
            root = root->p_next;
        }
    }
}

CompanyNode* Search(CompanyNode** HashTable, string company_name) {
    long long index = HashString(company_name) % 200;

    if (HashTable[index] == NULL) {
        return NULL;
    }

    CompanyNode* node = HashTable[index];

    while (node != NULL) {
        if (node->company.name == company_name) {
            return node;
        }
        node = node->p_next;
    }

    return NULL;
}

int main() {
    vector<Company> vect;
    vect = ReadCompanyList("MST.txt");
    // for(int i=0;i<vect.size();i++) {
    //     cout << vect[i].name << endl;
    //     cout << HashString(vect[i].name) << endl;
    //     cout << endl;
    // }
    CompanyNode** HashTable = CreateHashTable(vect);
    CompanyNode* c = Search(HashTable, "CONG TY TNHH BEE VIET NAM");
    cout << c->company.name << endl;
    CompanyNode* t = Search(HashTable, "CONG TY TNHH DICH VU VA PHAT TRIEN THUONG MAI KIM LONG");
    cout << t->company.name << endl;
    cout << HashString("CONG TY TNHH DICH VU VA PHAT TRIEN THUONG MAI KIM LONG") << endl;
    cout << specialPow(19);
    return 0;
}