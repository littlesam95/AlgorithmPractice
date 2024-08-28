#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int T, L, R, S;
int Answer;

void input() {
    cin >> T;
    while (T--) {
        cin >> L >> R >> S;
        int Left = (S - L) * 2;
        int Right = (R - S - 1) * 2 + 1;
        Answer = (Left < Right) ? Left : Right;
        cout << Answer + 1 << "\n";
    };
}

int main() {
    FASTIO
    input();

    return 0;
}