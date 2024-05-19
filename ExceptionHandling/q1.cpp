/*Write a function divide that takes two integers 
and returns the result of their division. Throw an exception if the divisor is zero.*/
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class Base {
    int a, b;

public:
    Base(int a, int b) : a(a), b(b) {}

    int divide() const {
        if (b == 0) {
            throw runtime_error("Can't be divided by zero.");
        } else {
            int result = a / b;
            return result;
        }
    }
};

int main() {
    try {
        Base b1(2, 3);
        cout << "Result of division: " << b1.divide() << endl;

        Base b2(2, 0);
        cout << "Result of division: " << b2.divide() << endl; // This will cause an exception
    } catch (const runtime_error& e) {
        cerr << "Caught exception: " << e.what() << endl;
    }

    return 0;
}
