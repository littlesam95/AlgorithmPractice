#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MAX 11
#define INF 1e9
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, M, K;
int MAP[MAX][MAX], Visited[MAX][MAX];
int Answer = -INF;

void input() {
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> MAP[i][j];
        }
    }
}

void dfs(int Depth, int Sum) {
    if (Depth == K) {
        Answer = max(Answer, Sum);
        return;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (Visited[i][j] == 0) {
                Visited[i][j]++;
                Visited[i + 1][j]++;
                Visited[i][j + 1]++;
                Visited[i - 1][j]++;
                Visited[i][j - 1]++;
                dfs(Depth + 1, Sum + MAP[i][j]);
                Visited[i][j - 1]--;
                Visited[i - 1][j]--;
                Visited[i][j + 1]--;
                Visited[i + 1][j]--;
                Visited[i][j]--;
            }
        }
    }
}

void settings() {
    dfs(0, 0);
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