#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct Examinee
{
    string id;
    float math, english, physic;
};

void OutputExaminee(Examinee e) {
    cout << "ID: " << e.id << endl;
    cout << "Math: " << e.math << endl;
    cout << "Physic: " << e.physic << endl;
    cout << "English: " << e.english << endl;
}

Examinee readExaminee(string line_info) {
    Examinee e;
    string temp = line_info;
    int pos = temp.find(" ");
    e.id = temp.substr(0, pos);
    temp = temp.substr(pos + 1);

    pos = temp.find(" ");
    e.math = stof(temp.substr(0, pos));
    temp = temp.substr(pos + 1);

    pos = temp.find(" ");
    e.physic = stof(temp.substr(0, pos));
    temp = temp.substr(pos + 1);

    pos = temp.find(" ");
    e.english = stof(temp.substr(0, pos));
    temp = temp.substr(pos + 1);
    return e;
}

Examinee* readExamineeList(string file_name, int& num) {
    Examinee* e = new Examinee[100];
    fstream input;
    input.open(file_name, ios::in);
    int i = 0, header = 1;
    while (!input.eof()) {
        string s;
        getline(input, s);
        if (s.empty() == 0 && header == 0) {
            e[i] = readExaminee(s);
            i++;
            num++;
        }
        header = 0;
    }
    for (int i = 0; i < num; i++) {
        cout << endl << "Examinee " << i + 1 << endl;
        OutputExaminee(e[i]);
    }
    return e;
}

void writeTotal(Examinee* examinee_list, string out_file_name, int num) {
    fstream output;
    output.open(out_file_name, ios::out);
    for (int i = 0; i < num; i++) {
        output << examinee_list[i].id << " " << examinee_list[i].math + examinee_list[i].physic + examinee_list[i].english << endl;
    }
}

int main() {
    fstream input;
    fstream output;
    Examinee* e = new Examinee[100];
    int num = 0;
    e = readExamineeList("data.txt", num);
    writeTotal(e, "output.txt", num);
    return 0;
}