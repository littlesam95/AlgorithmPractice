#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
string A, B;
int Answer;

void settings() {
    Answer = 0;
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    if (A.size() > B.size()) {
        int S = A.size() - B.size();
        while (S--) {
            B += "0";
        };
    }
    else if (B.size() > A.size()) {
        int S = B.size() - A.size();
        while (S--) {
            A += "0";
        };
    }
    int C = 0;
    for (int i = 0; i < A.size(); i++) {
        int CurA = A[i] - '0';
        int CurB = B[i] - '0';
        int Next = CurA + CurB + C;
        if (Next >= 10) {
            Answer++;
            C = Next / 10;
        }
    }
}

void find_Answer() {
    cout << Answer << "\n";
}

void input() {
    while (1) {
        cin >> A >> B;
        if ((A == "0") && (B == "0")) {
            break;
        }
        settings();
        find_Answer();
    };
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    input();
    
	return 0;
}