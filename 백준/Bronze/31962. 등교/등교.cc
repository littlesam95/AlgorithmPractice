#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, X, S, T;
int Answer = -1;

void input() {
    cin >> N >> X;
    for (int i = 0; i < N; i++) {
        cin >> S >> T;
        if ((S + T) <= X) {
            Answer = max(Answer, S);
        }
    }
    cout << Answer << "\n";
}

int main() {
    FASTIO
    input();

    return 0;
}