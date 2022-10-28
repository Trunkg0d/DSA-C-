#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct Examinee
{
    string id;
    string name;
    float math, english, physics;
};

struct ExamineeNode {
    Examinee examinee;
    ExamineeNode* p_next;
};

ExamineeNode* createNode(Examinee examinee) {
    ExamineeNode* node = new ExamineeNode;
    node->examinee = examinee;
    node->p_next = NULL;
    return node;
}

struct ExamineeList
{
    ExamineeNode* pFirst = NULL;
    ExamineeNode* pLast = NULL;
};

//Read Examinee by line info, return examinee
Examinee readExaminee(string& line) {
    Examinee examinee;

    string temp = line;

    int pos = temp.find(",");
    examinee.id = temp.substr(0, pos);
    temp = temp.substr(pos + 1);

    pos = temp.find(",");
    examinee.name = temp.substr(0, pos);
    temp = temp.substr(pos + 1);

    if (temp[0] == ' ') {
        examinee.math = -1;
        pos = temp.find(",");
        temp = temp.substr(pos + 1);
    }
    else {
        pos = temp.find(",");
        examinee.math = stof(temp.substr(0, pos));
        temp = temp.substr(pos + 1);
    }

    if (temp[0] == ' ') {
        examinee.english = -1;
        pos = temp.find(",");
        temp = temp.substr(pos + 1);
    }
    else {
        pos = temp.find(",");
        examinee.english = stof(temp.substr(0, pos));
        temp = temp.substr(pos + 1);
    }

    if (temp[0] == ' ') {
        examinee.physics = -1;
        pos = temp.find(",");
        temp = temp.substr(pos + 1);
    }
    else {
        pos = temp.find(",");
        examinee.physics = stof(temp.substr(0, pos));
        temp = temp.substr(pos + 1);
    }
    return examinee;
}

//Add examinee to list of examinee
void addTail(ExamineeList*& list, Examinee examinee) {
    ExamineeNode* node = createNode(examinee);
    if (list->pFirst == NULL) {
        list->pFirst = list->pLast = node;
    }
    else {
        list->pLast->p_next = node;
        list->pLast = node;
    }
}

//Print list of examinee
void printList(ExamineeList* list) {
    ExamineeNode* root = list->pFirst;
    while (root != NULL) {
        cout << "Student ID: " << root->examinee.id << endl;
        cout << "Name: " << root->examinee.name << endl;
        cout << "Math: " << root->examinee.math << "; English: " << root->examinee.english << "; Physisc: " << root->examinee.physics << endl;
        root = root->p_next;
        cout << "-------------" << endl;
    }
    cout << endl;

}

//Read examinee from examinee data file
ExamineeList* readData(string file_name) {
    ExamineeList* list = new ExamineeList;
    fstream input;
    input.open(file_name, ios::in);
    int heading = 1;
    while (!input.eof()) {
        string s;
        getline(input, s);
        if (s.empty() == false) {
            if (heading == 0) {
                Examinee e = readExaminee(s);
                addTail(list, e);
            }
            else {
                heading = 0;
            }
        }
    }
    return list;
}

//Check if examinee is invalid
bool check(Examinee e) {
    if (e.id.length() != 6) {
        return false;
    }
    if (e.english < 0 || e.english>10) {
        return false;
    }
    if (e.math < 0 || e.math > 10) {
        return false;
    }
    if (e.physics < 0 || e.physics > 10) {
        return false;
    }
    return true;
}

void removeHead(ExamineeList*& list) {
    if (list->pFirst == NULL) {
        cout << "List is empty" << endl;
    }
    else {
        ExamineeNode* temp = list->pFirst;
        list->pFirst = temp->p_next;
        delete temp;
    }
}

void removeTail(ExamineeList*& list) {
    if (list->pFirst == NULL) {
        cout << "List is empty" << endl;
    }
    else if (list->pLast == list->pFirst) {
        removeHead(list);
    }
    else {
        ExamineeNode* temp = list->pLast;
        ExamineeNode* root = list->pFirst;
        while (root != NULL) {
            if (root->p_next == list->pLast) {
                root->p_next = NULL;
                list->pLast = root;
                delete temp;
            }
            root = root->p_next;
        }
    }
}

//void removeAll(ExamineeList*& list) {
//    ExamineeNode* root = list->pFirst;
//    while (root != NULL) {
//        ExamineeNode* temp = list->pFirst;
//        root = root->p_next;
//        delete temp;
//    }
//    list->pFirst = list->pLast = NULL;
//}

//Remove invalid examinee from list
void removeInvalid(ExamineeList*& list) {
    ExamineeList* newlist = new ExamineeList;
    ExamineeNode* node = list->pFirst;
    while (node != NULL) {
        if (check(node->examinee) == true) {
            addTail(newlist, node->examinee);
        }
        node = node->p_next;
    }
    list = newlist;
}

//Cut name from full name
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

//Sort examinee list by math score, if math score is equal then sort by name (not full name)
void sortMath(ExamineeList*& list) {
    ExamineeNode* root = list->pFirst;
    while (root != NULL) {
        ExamineeNode* root1 = list->pFirst;
        while (root1->p_next != NULL) {
            if (root1->examinee.math > root->examinee.math) {
                swap(root1->examinee.id, root->examinee.id);
                swap(root1->examinee.name, root->examinee.name);
                swap(root1->examinee.math, root->examinee.math);
                swap(root1->examinee.english, root->examinee.english);
                swap(root1->examinee.physics, root->examinee.physics);
            }
            else if (root1->examinee.math == root->examinee.math) {
                if (cutName(root1->examinee.name) > cutName(root->examinee.name)) {
                    swap(root1->examinee.id, root->examinee.id);
                    swap(root1->examinee.name, root->examinee.name);
                    swap(root1->examinee.math, root->examinee.math);
                    swap(root1->examinee.english, root->examinee.english);
                    swap(root1->examinee.physics, root->examinee.physics);
                }
            }
            root1 = root1->p_next;
        }
        root = root->p_next;
    }
}

//Total score of examinee
float total(Examinee e) {
    float total = e.english + e.math + e.physics;
    return total;
}

//Check status of examinee: PASS or FAIL
bool checkStatus(Examinee e) {
    if (e.english < 5 || e.math < 5 || e.physics < 5 || total(e) <= 20) {
        return false;
    }
    return true;
}

//Sort examinee by status, then by total and name
void finalSort(ExamineeList*& list) {
    ExamineeNode* root = list->pFirst;
    while (root != NULL) {
        ExamineeNode* root1 = list->pFirst;
        while (root1->p_next != NULL) {
            if (checkStatus(root1->examinee) > checkStatus(root->examinee)) {
                swap(root1->examinee.id, root->examinee.id);
                swap(root1->examinee.name, root->examinee.name);
                swap(root1->examinee.math, root->examinee.math);
                swap(root1->examinee.english, root->examinee.english);
                swap(root1->examinee.physics, root->examinee.physics);
            }
            else if (checkStatus(root1->examinee) == checkStatus(root->examinee)) {
                if (total(root1->examinee) > total(root->examinee)) {
                    swap(root1->examinee.id, root->examinee.id);
                    swap(root1->examinee.name, root->examinee.name);
                    swap(root1->examinee.math, root->examinee.math);
                    swap(root1->examinee.english, root->examinee.english);
                    swap(root1->examinee.physics, root->examinee.physics);
                }
                else if (total(root1->examinee) == total(root->examinee)) {
                    if (cutName(root1->examinee.name) > cutName(root->examinee.name)) {
                        swap(root1->examinee.id, root->examinee.id);
                        swap(root1->examinee.name, root->examinee.name);
                        swap(root1->examinee.math, root->examinee.math);
                        swap(root1->examinee.english, root->examinee.english);
                        swap(root1->examinee.physics, root->examinee.physics);
                    }
                }
            }
            root1 = root1->p_next;
        }
        root = root->p_next;
    }
}

//Output data
void outputFile(ExamineeList* list, string file_name) {
    fstream output;
    output.open(file_name, ios::out);
    ExamineeNode* node = list->pFirst;
    while (node != NULL) {
        if (checkStatus(node->examinee) == true) {
            output << node->examinee.id << ", " << node->examinee.name << ", " << node->examinee.math << ", " << node->examinee.english << ", " << node->examinee.physics << ", " << total(node->examinee) << ", PASS" << endl;
        }
        else {
            output << node->examinee.id << ", " << node->examinee.name << ", " << node->examinee.math << ", " << node->examinee.english << ", " << node->examinee.physics << ", " << total(node->examinee) << ", FAIL" << endl;
        }
        node = node->p_next;
    }
}

int main() {
    //Output on screen Examinee List
    ExamineeList* list = readData("data.txt");
    printList(list);

    // Remove Invalid Examinee
    cout << "-------------" << endl;
    cout << "Remove Invalid Examinee: " << endl;
    cout << endl;
    removeInvalid(list);
    printList(list);

    //Sort Examinee List
    cout << "-------------" << endl;
    cout << "Sort Examinee List: " << endl;
    cout << endl;
    sortMath(list);
    printList(list);

    //Output file
    finalSort(list);
    outputFile(list, "output.txt");
    return 0;
}