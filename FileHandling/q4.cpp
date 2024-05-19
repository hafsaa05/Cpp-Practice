// Define a Student class with attributes name, age, and grade. 
// Implement methods to save and load student records to/from a text file using a FileHandler class.

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>

using namespace std;

class FileHandler {
    string fileName;

public:
    FileHandler(string fileName) : fileName(fileName) {}

    void writeLine(const string& line) {
        ofstream outFile(fileName, ios::app);
        try {
            if (!outFile) {
                throw runtime_error("Error opening file for writing!");
            }
        } catch (const runtime_error& e) {
            cerr << e.what() << endl; // Use cerr for error messages
            return;
        }
        outFile << line << endl;
        outFile.close();
    }

    void readLines() {
        ifstream inFile(fileName);
        try {
            if (!inFile) {
                throw runtime_error("Error opening file for reading!");
            }
        } catch (const runtime_error& e) {
            cerr << e.what() << endl; // Use cerr for error messages
            return;
        }

        string line;
        while (getline(inFile, line)) {
            cout << line << endl;
        }

        inFile.close();
    }
};

class Student {
    string name;
    int age;
    string grade; // Adding grade attribute

public:
    Student(string name, int age, string grade) : name(name), age(age), grade(grade) {}

    void saveToFile(FileHandler& fileHandler) {
        fileHandler.writeLine(name + ", " + to_string(age) + ", " + grade);
    }

    void display() const {
        cout << "Name: " << name << ", Age: " << age << ", Grade: " << grade << endl;
    }
};

int main() {
    FileHandler fileHandler("students.txt");

    Student s1("Hafsa", 18, "A");
    Student s2("Amna", 13, "B");

    s1.saveToFile(fileHandler);
    s2.saveToFile(fileHandler);

    // Load and display students
    cout << "Reading from file:" << endl;
    fileHandler.readLines();

    return 0;
}
