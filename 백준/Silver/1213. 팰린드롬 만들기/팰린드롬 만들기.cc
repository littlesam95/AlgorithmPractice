#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MAX 26
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
string S;
int MAP[MAX];
int Start = 25;
string Answer;

void input() {
    cin >> S;
}

void settings() {
    for (int i = 0; i < S.size(); i++) {
        int Now = S[i] - 'A';
        MAP[Now]++;
    }
    while (1) {
        if (Start == -1) {
            break;
        }
        if (MAP[Start] % 2 == 0) {
            Start--;
        }
        else {
            Answer += (char)(Start + 65);
            MAP[Start]--;
            break;
        }
    };
    for (int i = (MAX - 1); i >= 0; i--) {
        if (MAP[i] % 2 == 1) {
            Answer = "I'm Sorry Hansoo";
            break;
        }
        for (int j = 0; j < MAP[i]; j++) {
            if (j % 2 == 0) {
                Answer.insert(Answer.begin(), (char)(i + 65));
            }
            else {
                Answer.push_back((char)(i + 65));
            }
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