#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int T, N;
string S;

void init() {
    S = "";
}

void settings() {
    while (N > 0) {
        int R = N % 2;
        S += to_string(R);
        N /= 2;
    };
}

void find_Answer() {
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == '1') {
            cout << i << " ";
        }
    }
    cout << "\n";
}

void input() {
    cin >> T;
    while (T--) {
        init();
        cin >> N;
        settings();
        find_Answer();
    };
}

int main() {
    FASTIO
    input();

    return 0;
}