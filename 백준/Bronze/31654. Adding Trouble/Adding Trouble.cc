#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int A, B, C;

void input() {
    cin >> A >> B >> C;
    if (A + B == C) {
        cout << "correct!\n";
    }
    else {
        cout << "wrong!\n";
    }
}

int main() {
    FASTIO
    input();

    return 0;
}