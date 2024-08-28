#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int A, B, C, D;

void input() {
    cin >> A >> B >> C;
    cin >> D;
    C += D;
    if (C >= 60) {
        B += (C / 60);
        C %= 60;
    }
    if (B >= 60) {
        A += (B / 60);
        B %= 60;
    }
    if (A >= 24) {
        A %= 24;
    }
    cout << A << " " << B << " " << C << "\n";
}

int main() {
    FASTIO
    input();

    return 0;
}