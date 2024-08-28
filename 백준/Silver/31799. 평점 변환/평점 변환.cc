#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N;
string S, Prev;
string Answer;

void input() {
    cin >> N;
    cin >> S;
}

void settings() {
    for (int i = 0; i < (int)S.length(); i++) {
        string Now = "";
        Now += S[i];
        bool jump = false;
        if (i < ((int)S.length() - 1)) {
            if ((S[i + 1] == '+') || (S[i + 1] == '0') || (S[i + 1] == '-')) {
                Now += S[i + 1];
                jump = true;
            }
            else {
                Now += "0";
            }
        }
        else {
            Now += "0";
        }

        if ((Now == "C+") || (Now == "C0") || (Now == "C-")) {
            Answer += "B";
        }
        else if ((Now == "B0") || (Now == "B-")) {
            if ((Prev == "") || (Prev == "C+") || (Prev == "C0") || (Prev == "C-")) {
                Answer += "D";
            }
            else {
                Answer += "B";
            }
        }
        else if ((Now == "A-") || (Now == "B+")) {
            if ((Prev == "") || (Prev == "B0") || (Prev == "B-") || (Prev == "C+") || (Prev == "C0") || (Prev == "C-")) {
                Answer += "P";
            }
            else {
                Answer += "D";
            }
        }
        else if (Now == "A0") {
            if ((Prev == "A+") || (Prev == "A0")) {
                Answer += "P";
            }
            else {
                Answer += "E";
            }
        }
        else if (Now == "A+") {
            Answer += "E";
        }
        Prev = Now;

        if (jump) {
            i++;
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