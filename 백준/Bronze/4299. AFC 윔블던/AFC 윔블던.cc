#include <iostream>
#include <algorithm>

using namespace std;
int A, B, N, M;

void Input() {
    cin >> A >> B;
}

void Settings() {
    N = (A + B) / 2;
    M = (A - B) / 2;
}

void Find_Answer() {
    if (A < B) {
        cout << -1 << "\n";
        return;
    }
    if ((N + M == A) && (N - M == B)) {
        cout << N << " " << M << "\n";
    }
    else {
        cout << -1 << "\n";
    }
}

int main() {
    Input();
    Settings();
    Find_Answer();
    
    return 0;
}