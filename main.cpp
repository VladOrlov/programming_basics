#include <iostream>
#include <functional>
#include <cmath>
#include "lab1.h"
#include "lab2.h"
#include "lab3.h"
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <malloc.h>

#define PI 3.14159265

using namespace std;

static map<string, int> predefined_args = {
        {"lab1", 1},
        {"lab2", 2},
        {"lab3", 3},
};

void execute(map<string, int> predefined_args, string start_arg);

int execute_lab1() {
    lab1 l;
    return l.execute();
}

int execute_lab2() {
    lab2 l;
    return l.execute();
}

int execute_lab3() {
    lab3 l;
    return l.execute();
}

bool is_arg_prefix(string arg_prefix) {
    string dash("-");
    return dash.compare(arg_prefix) == 0;
}

void printHelp() {
    cout << "Available options for application launch:" << endl;
    for (auto &item : predefined_args) {
        cout << "-" + item.first << endl;
    }
}

string get_argument_value(string str) {

    vector<char> current_arg(str.begin(), str.end());
    vector<char> arg_value;

    for (int i = 1; i < current_arg.size(); i++) {
        arg_value.push_back(current_arg[i]);
    }

    string arg(arg_value.begin(), arg_value.end());

    return arg;
}

int main(int argc, const char *argv[]) {

    set<string> passed_arguments;

    for (int i = argc; i > 0; i--) {
        const char *current_arg = argv[i - 1];

        string first_symbol(1, current_arg[0]);

        if (is_arg_prefix(first_symbol)) {
            string arg_value = get_argument_value(string(current_arg));
            passed_arguments.insert(arg_value);
        }
    }

    for (auto &arg : passed_arguments) {
        execute(predefined_args, arg);
    }
}

void execute(map<string, int> predefined_args, string start_arg) {
    int arg_binding = 0;
    try {
        arg_binding = predefined_args.at(start_arg);
    } catch (exception &e) {
        cout << "I wish I had possibility to execute get from map without try-catch block in C++" << endl;
    }

    switch (arg_binding) {
        case 1:
            execute_lab1();
            break;
        case 2:
            execute_lab2();
            break;
        case 3:
            execute_lab3();
            break;
        default:
            cout << "Wrong argument received!" << endl;
            printHelp();
    }
}