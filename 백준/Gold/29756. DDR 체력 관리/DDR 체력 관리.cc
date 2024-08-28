#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MAX_N 1001
#define MAX_H 101
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, K;
int S[MAX_N], H[MAX_N];
int DP[MAX_N][MAX_H];
int Answer;

void input() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> S[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> H[i];
    }
}

int top_Down(int Depth, int Health) {
    if (Depth == 0) {
        return 0;
    }

    int NextHealth = min(Health + K, 100);
    if (DP[Depth][NextHealth] != 0) {
        return DP[Depth][NextHealth];
    }

    int Result = top_Down(Depth - 1, NextHealth);
    if (NextHealth - H[Depth] >= 0) {
        Result = max(Result, top_Down(Depth - 1, NextHealth - H[Depth]) + S[Depth]);
    }

    return DP[Depth][NextHealth] = Result;
}

void settings() {
    Answer = top_Down(N, 100);
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