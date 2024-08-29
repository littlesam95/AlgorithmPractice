#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0);

using namespace std;
int T;
int Alpha[26];
int Answer;

void init() {
    for (int i = 0; i < 26; i++) {
        Alpha[i] = 0;
    }
    Answer = 0;
}

void input() {
    cin >> T;
    while (T--) {
        init();
        string S;
        cin >> S;
        for (int i = 0; i < S.size(); i++) {
            char C = S[i];
            Alpha[C -  'A']++;
        }
        for (int i = 0; i < 26; i++) {
            if (Alpha[i] == 0) {
                Answer += (i + 65);
            }
        }
        cout << Answer << "\n";
    };
}

int main() {
    FASTIO
    input();

    return 0;
}