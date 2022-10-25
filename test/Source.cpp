#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct Examinee{
	string id;
	float math, english, physic;
};

Examinee readExaminee(string line_info){
	Examinee e;
	string temp = line_info;
	e.id = temp.substr(0, temp.find(","));
	temp = temp.substr(temp.find(",") + 1);

	e.math = stof((temp.substr(0, temp.find(","))));
	temp = temp.substr(temp.find(",") + 1);

	e.physic = stof((temp.substr(0, temp.find(","))));
	temp = temp.substr(temp.find(",") + 1);

	e.english = stof((temp.substr(0, temp.find(","))));
	temp = temp.substr(temp.find(",") + 1);
	return e;
}

void outputExaminee(Examinee e){
	cout << "Id: " << e.id << endl;
	cout << "Math: " << e.math << endl;
	cout << "Physic: " << e.physic << endl;
	cout << "English: " << e.english << endl;
	cout << "--------------------" << endl;
}

Examinee* readExamineeList(string file_name){
	fstream input;
	Examinee* e = new Examinee[100];
	input.open(file_name, ios::in);
	int i=0, heading =1;
	while(!input.eof()){
		string s;
		input >> s;
		if(s.empty() == 0 && heading == 0){
			e[i] = readExaminee(s);
			outputExaminee(e[i]);
			i++;
		} else{
			heading = 0;
		}
	}
	return e;
}

void writeTotal(Examinee* examinee_list, string out_file_name){
	fstream output;
	output.open(out_file_name, ios::out);
	for(int i=0;; i++){
		if(examinee_list[i].id.empty() == 1){
			break;
		}
		output << examinee_list[i].id << " " << examinee_list[i].math + examinee_list[i].physic + examinee_list[i].english << endl;
	}
}

int main(){
	Examinee* e = new Examinee[100];
	e = readExamineeList("data.txt");
	writeTotal(e, "output.txt");
	return 0;
}