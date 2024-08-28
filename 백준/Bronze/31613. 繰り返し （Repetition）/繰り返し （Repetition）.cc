#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int X, N;
int Answer;

void input() {
    cin >> X;
    cin >> N;
    while (X < N) {
        int R = X % 3;
        if (R == 0) {
            X += 1;
        }
        else if (R == 1) {
            X *= 2;
        }
        else {
            X *= 3;
        }
        Answer++;
    };
    cout << Answer << "\n";
}

int main() {
    FASTIO
    input();

    return 0;
}