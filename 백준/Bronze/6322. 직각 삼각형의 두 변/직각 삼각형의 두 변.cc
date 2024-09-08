#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
int Index = 1;
double A, B, C;
double Answer;

void find_Answer() {
    Answer = -1;
    string Which;
    if (A == -1) {
        A = sqrt((C * C) - (B * B));
        if ((A + B >= C) && (A > 0)) {
            Answer = A;
            Which = "a";
        }
    }
    else if (B == -1) {
        B = sqrt((C * C) - (A * A));
        if ((A + B >= C) && (B > 0)) {
            Answer = B;
            Which = "b";
        }
    }
    else if (C == -1) {
        C = sqrt((A * A) + (B * B));
        if ((A + B >= C) && (C > 0)) {
            Answer = C;
            Which = "c";
        }
    }
    cout << "Triangle #" << Index++ << "\n";
    cout << fixed;
    cout.precision(3);
    if (Answer == -1) {
        cout << "Impossible.\n";
    }
    else {
        cout << Which << " = " << Answer << "\n";
    }
}

void input() {
    while (1) {
        cin >> A >> B >> C;
        if ((A == 0) && (B == 0) && (C == 0)) {
            break;
        }
        find_Answer();
        cout << "\n";
    };
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    input();
    
	return 0;
}