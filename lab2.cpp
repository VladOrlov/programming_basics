#include "lab2.h"
#include <iostream>
#include <cmath>

using namespace std;

int lab2::execute() {

    string a_input = "";
    string x_input = "";

    cout << "Please enter number for a:\n>";
    getline(cin, a_input);

    cout << "Please enter number for x:\n>";
    getline(cin, x_input);

    try {
        int a = stoi(a_input);
        int x = stoi(x_input);

        double y = a * pow(x, 4) * log(a + x) / (pow(a * x, 1 / 3) - exp(sqrt(x)));

        cout << "a : " << a << endl;
        cout << "x : " << x << endl;
        cout << "y : " << y << endl;
    } catch (int i) {

    }
}
