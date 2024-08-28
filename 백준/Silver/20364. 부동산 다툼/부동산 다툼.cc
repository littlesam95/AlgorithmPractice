#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, Q, X;
bool DP[2 << 20];

void input() {
    cin >> N >> Q;
    while (Q--) {
        cin >> X;
        int Answer = 0;
        int TmpX = X;
        while (TmpX > 1) {
            if (DP[TmpX]) {
                Answer = TmpX;
            }
            int NextX = TmpX / 2;
            TmpX = NextX;
        };
        DP[X] = true;
        cout << Answer << "\n";
    };
}

int main() {
    FASTIO
    input();

    return 0;
}