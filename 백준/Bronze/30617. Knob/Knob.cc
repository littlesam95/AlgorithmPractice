#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, A, B, L, R;
int Answer;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> L >> R;
        if (i > 0) {
            if ((A == L) && (A != 0)) Answer++;
            if ((B == R) && (B != 0)) Answer++;
        }
        if ((L == R) && (L != 0)) Answer++;
        A = L;
        B = R;
    }

    cout << Answer << "\n";
}

int main() {
    FASTIO
    input();

    return 0;
}