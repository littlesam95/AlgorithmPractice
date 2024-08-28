#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int B, C;
string S;

void input() {
    cin >> S;
    for (int i = 0; i < (int)S.length(); i++) {
        if (S[i] == 'B') {
            B++;
        }
        else {
            C++;
        }
    }
    cout << (B / 2) + (C / 2) << "\n";
}

int main() {
    FASTIO
    input();

    return 0;
}