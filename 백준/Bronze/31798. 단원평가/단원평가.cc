#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int A, B, C;
int Answer;

void input() {
    cin >> A >> B >> C;
}

void settings() {
    if (A == 0) {
        Answer = pow(C, 2) - B;
    }
    else if (B == 0) {
        Answer = pow(C, 2) - A;
    }
    else if (C == 0) {
        Answer = sqrt(A + B);
    }
}

void find_Answer() {
    cout << Answer << "\n";
}

int main() {
    FASTIO
    input();
    settings();
    find_Answer();

    return 0;
}