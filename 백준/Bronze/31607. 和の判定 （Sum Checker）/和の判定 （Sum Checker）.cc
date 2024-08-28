#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int A, B, C;

void input() {
    cin >> A;
    cin >> B;
    cin >> C;
    if ((A + B == C) || (A + C == B) || (B + C == A)) {
        cout << "1\n";
    }
    else {
        cout << "0\n";
    }
}

int main() {
    FASTIO
    input();

    return 0;
}