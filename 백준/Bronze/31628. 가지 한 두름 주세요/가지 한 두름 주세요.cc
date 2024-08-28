#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MAX 11
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
string S[MAX][MAX];
int Answer;

void input() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> S[i][j];
        }
    }
    for (int i = 0; i < 10; i++) {
        bool Flag = true;
        for (int j = 0; j < 9; j++) {
            if (S[i][j] != S[i][j + 1]) {
                Flag = false;
            }
        }
        if (Flag) {
            Answer = 1;
        }
    }
    for (int i = 0; i < 10; i++) {
        bool Flag = true;
        for (int j = 0; j < 9; j++) {
            if (S[j][i] != S[j + 1][i]) {
                Flag = false;
            }
        }
        if (Flag) {
            Answer = 1;
        }
    }
    cout << Answer << "\n";
}

int main() {
    FASTIO
    input();

    return 0;
}