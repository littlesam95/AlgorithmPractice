#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MAX 1001
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, T, SumM;
int D[MAX], M[MAX];
int DP[MAX][MAX];
int Answer;

void input() {
    cin >> N >> T;
    for (int i = 1; i <= N; i++) {
        cin >> D[i] >> M[i];
        SumM += M[i];
    }
}

int top_Down(int Depth, int Day) {
    if (Depth == 0) {
        return 0;
    }

    if (DP[Depth][Day] != 0) {
        return DP[Depth][Day];
    }

    int Result = top_Down(Depth - 1, Day);
    if (Day - D[Depth] >= 0) {
        Result = max(Result, top_Down(Depth - 1, Day - D[Depth]) + M[Depth]);
    }

    return DP[Depth][Day] = Result;
}

void settings() {
    Answer = SumM - top_Down(N, T);
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