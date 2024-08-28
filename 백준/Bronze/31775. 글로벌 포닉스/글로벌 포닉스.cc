#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
string S[3];
bool L, K, P;

void input() {
    for (int i = 0; i < 3; i++) {
        cin >> S[i];
        if (S[i][0] == 'l') {
            L = true;
        }
        else if (S[i][0] == 'k') {
            K = true;
        }
        else if (S[i][0] == 'p') {
            P = true;
        }
    }
    if (L && K && P) {
        cout << "GLOBAL\n";
    }
    else {
        cout << "PONIX\n";
    }
}

int main() {
    FASTIO
    input();

    return 0;
}