#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
string S;
int Cnt_Upper;
int Answer;

void input() {
    cin >> S;
}

void settings() {
    Answer = (int)S.length();
    for (int i = 0; i < (int)S.size(); i++) {
        char Now = S[i];
        if ((Now >= 'A') && (Now <= 'Z')) {
            if (Cnt_Upper == 0) {
                Answer++;
            }
            Cnt_Upper++;
        }
        else {
            if (Cnt_Upper > 1) {
                Answer++;
                if (i < ((int)S.size() - 1)) {
                    char Next = S[i + 1];
                    if ((Next >= 'a') && (Next <= 'z')) {
                        Cnt_Upper = 0;
                    }
                }
            }
            else if (Cnt_Upper == 1) {
                Cnt_Upper = 0;
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