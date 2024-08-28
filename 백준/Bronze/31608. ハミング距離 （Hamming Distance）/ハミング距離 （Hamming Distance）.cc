#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N;
string S, T;
int Answer;

void input() {
    cin >> N;
    cin >> S;
    cin >> T;
    for (int i = 0; i < N; i++) {
        if (S[i] != T[i]) {
            Answer++;
        }
    }
    cout << Answer << "\n";
}

int main() {
    FASTIO
    input();

    return 0;
}