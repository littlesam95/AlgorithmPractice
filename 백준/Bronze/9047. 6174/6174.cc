#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int T, N;
int Answer;

void settings() {
    string S = to_string(N);
    sort(S.begin(), S.end());
    while ((int)S.length() < 4) {
        S = "0" + S;
    };
    string newS = S;
    reverse(newS.begin(), newS.end());
    N = abs(stoi(newS) - stoi(S));
    Answer++;
}

void input() {
    cin >> T;
    while (T--) {
        Answer = 0;
        cin >> N;
        while (N != 6174) {
            settings();
        };
        cout << Answer << "\n";
    };
}

int main() {
    FASTIO
    input();

    return 0;
}