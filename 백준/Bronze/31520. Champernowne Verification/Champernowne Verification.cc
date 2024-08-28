#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
string S;
bool Answer = true;

void input() {
    cin >> S;
    if (S[0] != '1') {
        cout << "-1\n";
        return;
    }
    for (int i = 0; i < ((int)S.size() - 1); i++) {
        int Now = S[i] - '0';
        int Next = S[i + 1] - '0';
        if (Now + 1 != Next) {
            Answer = false;
            break;
        }
    }
    if (Answer) {
        cout << S[(int)S.size() - 1] << "\n";
    }
    else {
        cout << "-1\n";
    }
}

int main() {
    FASTIO
    input();

    return 0;
}