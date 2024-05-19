//a program to read the content of the file created in question 1 and display it.
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
using namespace std;

int main() {
    ifstream myfile;
    myfile.open("zoom.txt", ios::out); 

     try {
         if (!myfile) {
             throw runtime_error("File can't open!");
         }
     } catch (const runtime_error& e) {
         cerr << e.what() << endl;
         return 1;  
     }

    char c;
    c = myfile.get();

    while(!myfile.eof()){

        cout<<c;
        c = myfile.get();
    };
    
    myfile.close();
    return 0;
}
