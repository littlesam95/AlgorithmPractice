#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int A, B;

void input() {
    cin >> A >> B;
    if (A == 0) {
        if (B == 0) {
            cout << "=\n";
        }
        else if (B == 2) {
            cout << ">\n";
        }
        else if (B == 5) {
            cout << "<\n";
        }
        else {
            cout << ">\n";
        }
    }
    else if (A == 2) {
        if (B == 0) {
            cout << "<\n";
        }
        else if (B == 2) {
            cout << "=\n";
        }
        else if (B == 5) {
            cout << ">\n";
        }
        else {
            cout << ">\n";
        }
    }
    else if (A == 5) {
        if (B == 0) {
            cout << ">\n";
        }
        else if (B == 2) {
            cout << "<\n";
        }
        else if (B == 5) {
            cout << "=\n";
        }
        else {
            cout << ">\n";
        }
    }
    else {
        if ((B == 0) || (B == 2) || (B == 5)) {
            cout << "<\n";
        }
        else {
            cout << "=\n";
        }
    }
}

int main() {
    FASTIO
    input();

    return 0;
}