#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N;
string S;
stack<char> C;
int Answer;

void input() {
    cin >> N;
    while (N--) {
        while (!C.empty()) {
            C.pop();
        }
        cin >> S;
        for (int i = 0; i < S.size(); i++) {
            if (C.empty()) {
                C.push(S[i]);
            }
            else {
                if (S[i] == C.top()) {
                    C.pop();
                }
                else {
                    C.push(S[i]);
                }
            }
        }
        if (C.empty()) {
            Answer++;
        }
    };
}

void find_Answer() {
    cout << Answer << "\n";
}

int main() {
    FASTIO
    input();
    find_Answer();

    return 0;
}