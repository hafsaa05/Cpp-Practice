//a program to create a file and write your name and age to it
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
using namespace std;

int main() {
    fstream myfile;
    myfile.open("zoom.txt", ios::out);  
    try {
        if (!myfile) {
            throw runtime_error("File can't open!");
        }
    } catch (const runtime_error& e) {
        cerr << e.what() << endl;
        return 1;  
    }

    string name = "hafsa";
    int age = 18;
    myfile << "Name: " << name << endl;
    myfile << "Age: " << age << endl;

    myfile.close();
    return 0;
}
