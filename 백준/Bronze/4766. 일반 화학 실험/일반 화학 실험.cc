#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
double Before = -20.00;
double After = 30.00;

void input() {
    while (1) {
        cin >> After;
        if (After == 999) {
            break;
        }
        if (Before == -20.00) {
            Before = After;
        }
        else {
            cout << fixed;
            cout.precision(2);
            cout << After - Before << "\n";
            Before = After;
        }
    };
}

int main() {
    FASTIO
    input();

    return 0;
}