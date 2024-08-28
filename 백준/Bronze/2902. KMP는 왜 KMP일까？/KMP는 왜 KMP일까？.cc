#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
string S;
string Answer;

void input() {
    cin >> S;
}

void settings() {
    Answer += S[0];
    for (int i = 1; i < S.size(); i++) {
        if (S[i] == '-') {
            Answer += S[i + 1];
        }
    }
}

void find_Answer() {
    cout << Answer << "\n";
}

int main() {
    FASTIO
    input();
    settings();
    find_Answer();

    return 0;
}