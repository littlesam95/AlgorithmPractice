#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
string S;

void input() {
    cin >> S;
    cout << S[0];
    for (int i = 1; i < ((int)S.length() - 1); i++) {
        cout << S[i] << S[i];
    }
    cout << S[(int)S.length() - 1] << "\n";
}

int main() {
    FASTIO
    input();

    return 0;
}