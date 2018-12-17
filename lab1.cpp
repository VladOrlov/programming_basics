#include "lab1.h"
#include <iostream>
#include <functional>
#include <cmath>

#define PI 3.14159265

using namespace std;

int lab1::execute() {

    string a_input = "";
    string x_input = "";

    cout << "Please enter number for a:\n>";
    getline(cin, a_input);

    cout << "Please enter number for x:\n>";
    getline(cin, x_input);
    try {
        int a = stoi(a_input);
        int x = stoi(x_input);
        double y;

        if (x > 6) {
            y = cos(a * x * PI / 180);
            cout << "y : " << y << endl;
            y = cos(a * x);
            cout << "y : " << y << endl;
        } else if (x < 6) {
            y = abs(a + x);
            cout << "y : " << y << endl;
        } else {
            cout << "Value 6 is unprocessable" << endl;
        }
    } catch (int i) {

    }


    return 0;

}
