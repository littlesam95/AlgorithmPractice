#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
string S;

void input() {
    cin >> S;
    for (int i = 0; i < (int)S.length(); i++) {
        cout << S[i];
        if ((i + 1) % 10 == 0) {
            cout << "\n";
        }
    }
}

int main() {
    FASTIO
    input();

    return 0;
}