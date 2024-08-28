#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, M;
string S;
int Answer;

void input() {
    cin >> N;
    cin >> S;
}

void settings() {
    for (int i = 0; i < (int)S.size(); i++) {
        char Now = S[i];
        if (Now == '(') {
            M++;
        }
        else {
            M--;
        }
        Answer = max(Answer, abs(M));
    }
}

void find_Answer() {
    if (M == 0) {
        cout << Answer << "\n";
    }
    else {
        cout << "-1\n";
    }
}

int main() {
    FASTIO
    input();
    settings();
    find_Answer();

    return 0;
}