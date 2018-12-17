#include "lab3.h"
#include <iostream>
#include <cmath>

using namespace std;

double calculateLeftPart(double x) {
    return (1 + x) / (1 + pow(x, 3));
}

double calculateRightPart(int k, double x) {
    return abs(pow(k, 1 / 3) - x);
}

int lab3::execute() {

    string k_input = "";

    cout << "Please enter value for variable k:\n>";
    getline(cin, k_input);

    try {
        int k = stoi(k_input);
        double y = 0;

        double x = -1.0;

        while (x <= 1.0) {
            double leftPart = calculateLeftPart(x);
            double rightPart = 0.0;
            for (int j = 7; j <= 10; j++) {
                if (rightPart == 0.0) {
                    rightPart = calculateRightPart(k, x);
                } else {
                    rightPart = rightPart * calculateRightPart(k, x);
                }
            }
            y = leftPart * rightPart;
            cout << "for x : " << x << " y : " << y << endl;
            x = x + 0.1;
        }
    } catch (int i) {
        return i;
    }

    return 0;
}

