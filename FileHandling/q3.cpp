// a program to copy the contents of one file to another
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>

using namespace std;

int main() {
    ifstream infile;
    infile.open("abc.txt"); // source file
    ofstream outfile;
    outfile.open("def.txt"); // destination file

    try {
        if (!infile) {
            throw runtime_error("Source File can't open!");
        }
        if (!outfile) {
            throw runtime_error("Destination File can't open!");
        }
    } catch (const runtime_error& e) {
        cerr << e.what() << endl; // Use cerr for error messages
        return 1;
    }

    string line;
    while (getline(infile, line)) {
        outfile << line << endl;
    }

    infile.close();
    outfile.close();

    return 0;
}
