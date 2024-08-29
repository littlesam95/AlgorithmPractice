#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int A, B, C;

void input() {
    cin >> A >> B >> C;
}

void find_Answer() {
    if (A + B == C) {
        cout << A << "+" << B << "=" << C << "\n";
        return;
    }
    else if (A - B == C) {
        cout << A << "-" << B << "=" << C << "\n";
        return;
    }
    else if (A * B == C) {
        cout << A << "*" << B << "=" << C << "\n";
        return;
    }
    else if (A / B == C) {
        cout << A << "/" << B << "=" << C << "\n";
        return;
    }
    else if (B + C == A) {
        cout << A << "=" << B << "+" << C << "\n";
        return;
    }
    else if (B - C == A) {
        cout << A << "=" << B << "-" << C << "\n";
        return;
    }
    else if (B * C == A) {
        cout << A << "=" << B << "*" << C << "\n";
        return;
    }
    else if (B / C == A) {
        cout << A << "=" << B << "/" << C << "\n";
        return;
    }
}

int main() {
    FASTIO
    input();
    find_Answer();

    return 0;
}