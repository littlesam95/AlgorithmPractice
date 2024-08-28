#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
string A, B;
char C;
string Answer;

void input() {
    cin >> A;
    cin >> C;
    cin >> B;
}

void settings() {
    if (C == '+') {
        if (A.size() >= B.size()) {
            int Sub = A.size() - B.size();
            while (Sub--) {
                B = "0" + B;
            };
            for (int i = 0; i < (int)A.size(); i++) {
                int Now = (A[i] - '0') + (B[i] - '0');
                Answer += to_string(Now);
            }
        }
        else {
            int Sub = B.size() - A.size();
            while (Sub--) {
                A = "0" + A;
            };
            for (int i = 0; i < (int)B.size(); i++) {
                int Now = (A[i] - '0') + (B[i] - '0');
                Answer += to_string(Now);
            }
        }
    }
    else {
        for (int i = 0; i < ((int)B.size() - 1); i++) {
            A += "0";
        }
        Answer = A;
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