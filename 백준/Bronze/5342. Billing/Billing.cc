#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
string S;
unordered_map<string, double> UM;
double Answer;

void input() {
    UM["Paper"] = 57.99;
    UM["Printer"] = 120.50;
    UM["Planners"] = 31.25;
    UM["Binders"] = 22.50;
    UM["Calendar"] = 10.95;
    UM["Notebooks"] = 11.20;
    UM["Ink"] = 66.95;

    while (getline(cin, S) && S != "EOI") {
        Answer += UM[S];
    };

    cout << fixed;
    cout.precision(2);
    cout << "$" << Answer << "\n";
}

int main() {
    FASTIO
    input();

    return 0;
}