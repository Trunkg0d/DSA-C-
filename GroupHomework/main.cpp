#include<iostream>
#include<string>
#include"dirent.h"

using namespace std;

int main () {
    DIR *directory;
    struct dirent *entry;
    
    directory = opendir("C:/Users/Trung");
    
    if (directory == NULL) {
        cout << "Not found directory" << endl;
        return 0;
    }
    
    while ((entry = readdir(directory))) {
        if ( (entry->d_type == DT_DIR) && (entry->d_name[0] != '.') ) {
            cout << "dir: " << entry->d_name << endl;
        }
        if ( (entry->d_type == DT_REG) && (entry->d_name[0] != '.') ) {
            cout << "file: " << entry->d_name << endl;
        }
    }
    
    if (closedir(directory) == -1) {
        cout << "Error closing directory" << endl;
        return 0;
    }
    
    return 0;
}