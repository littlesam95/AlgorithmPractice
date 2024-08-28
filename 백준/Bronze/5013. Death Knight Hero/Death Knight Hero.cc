#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#define MAX 101
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N;
string S;
int Answer;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> S;

        bool Flag = true;
        for (int j = 0; j < (int)S.length(); j++) {
            if ((S[j] == 'C') && (S[j + 1] == 'D')) {
                Flag = false;
            }
        }

        if (Flag) {
            Answer++;
        }
    }
    cout << Answer << "\n";
}

int main() {
    FASTIO
    input();

    return 0;
}