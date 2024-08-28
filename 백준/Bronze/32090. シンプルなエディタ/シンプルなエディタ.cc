#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, I;
string A, C;
string Answer;

void init() {
    I = 0;
    Answer.clear();
}

void settings() {
    if (A == "INSERT") {
        Answer.insert(I, C);
        I++;
    }
    else if (A == "LEFT") {
        I--;
        if (I < 0) {
            I = 0;
        }
    }
    else {
        I++;
        if (I > (int)Answer.length()) {
            I = (int)Answer.length();
        }
    }
}

void find_Answer() {
    cout << Answer << "\n";
}

void input() {
    while (1) {
        init();
        cin >> N;
        if (N == 0) break;
        for (int i = 0; i < N; i++) {
            cin >> A >> C;
            settings();
        }
        find_Answer();
    };
}

int main() {
    FASTIO
    input();

    return 0;
}