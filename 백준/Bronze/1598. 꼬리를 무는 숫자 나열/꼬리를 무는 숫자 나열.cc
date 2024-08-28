#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int A, B, Y1, X1, Y2, X2;
int Answer;

void input() {
    cin >> A >> B;
}

void settings() {
    if (A % 4 == 0) {
        Y1 = (A / 4) - 1;
        X1 = 3;
    }
    else {
        Y1 = (A / 4);
        X1 = (A % 4) - 1;
    }

    if (B % 4 == 0) {
        Y2 = (B / 4) - 1;
        X2 = 3;
    }
    else {
        Y2 = (B / 4);
        X2 = (B % 4) - 1;
    }

    Answer = abs(Y1 - Y2) + abs(X1 - X2);
}

void find_Answer() {
    cout << Answer << "\n";;
}

int main() {
    FASTIO
    input();
    settings();
    find_Answer();

    return 0;
}