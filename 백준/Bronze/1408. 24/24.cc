#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
string S, E;
int SM, EM, Sub;
string Answer;

void input() {
    cin >> S;
    cin >> E;
}

void settings() {
    SM += ((stoi(S.substr(0, 2)) * 3600) + (stoi(S.substr(3, 2)) * 60) + (stoi(S.substr(6, 2))));
    EM += ((stoi(E.substr(0, 2)) * 3600) + (stoi(E.substr(3, 2)) * 60) + (stoi(E.substr(6, 2))));
    Sub = EM - SM;
    if (Sub < 0) {
        Sub += 86400;
    }
    int H = Sub / 3600;
    string AH = to_string(H);
    if (AH.length() == 1) {
        AH = "0" + AH;
    }
    Sub -= (H * 3600);
    int M = Sub / 60;
    string AM = to_string(M);
    if (AM.length() == 1) {
        AM = "0" + AM;
    }
    Sub -= (M * 60);
    string AS = to_string(Sub);
    if (AS.length() == 1) {
        AS = "0" + AS;
    }
    Answer = AH + ":" + AM + ":" + AS;
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