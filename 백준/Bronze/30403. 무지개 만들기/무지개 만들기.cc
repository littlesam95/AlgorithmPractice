#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MAX 26
#define INF 1e9
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N;
string S;
int Upper[MAX], Lower[MAX];
int AnswerU = INF, AnswerL = INF;

void input() {
    cin >> N;
    cin >> S;
}

void settings() {
    for (int i = 0; i < N; i++) {
        char Now = S[i];
        if ((Now >= 'A') && (Now <= 'Z')) {
            Upper[Now - 'A']++;
        }
        else {
            Lower[Now - 'a']++;
        }
    }
    AnswerU = min(AnswerU, Upper['R' - 'A']);
    AnswerU = min(AnswerU, Upper['O' - 'A']);
    AnswerU = min(AnswerU, Upper['Y' - 'A']);
    AnswerU = min(AnswerU, Upper['G' - 'A']);
    AnswerU = min(AnswerU, Upper['B' - 'A']);
    AnswerU = min(AnswerU, Upper['I' - 'A']);
    AnswerU = min(AnswerU, Upper['V' - 'A']);
    AnswerL = min(AnswerL, Lower['r' - 'a']);
    AnswerL = min(AnswerL, Lower['o' - 'a']);
    AnswerL = min(AnswerL, Lower['y' - 'a']);
    AnswerL = min(AnswerL, Lower['g' - 'a']);
    AnswerL = min(AnswerL, Lower['b' - 'a']);
    AnswerL = min(AnswerL, Lower['i' - 'a']);
    AnswerL = min(AnswerL, Lower['v' - 'a']);
}

void find_Answer() {
    if ((AnswerU > 0) && (AnswerL > 0)) {
        cout << "YeS\n";
    }
    else if (AnswerU > 0) {
        cout << "YES\n";
    }
    else if (AnswerL > 0) {
        cout << "yes\n";
    }
    else {
        cout << "NO!\n";
    }
}

int main() {
    FASTIO
    input();
    settings();
    find_Answer();

    return 0;
}