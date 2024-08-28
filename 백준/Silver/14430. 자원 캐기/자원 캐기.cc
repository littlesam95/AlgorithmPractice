#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MAX 301
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, M;
int MAP[MAX][MAX];
int DP[MAX][MAX];

void input() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> MAP[i][j];
        }
    }
}

void settings() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]) + MAP[i][j];
        }
    }
}

void find_Answer() {
    cout << DP[N][M] << "\n";
}

int main() {
    FASTIO
    input();
    settings();
    find_Answer();

    return 0;
}