#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#define MAX 301
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, M;
int MAP[MAX][MAX];
bool Visited[MAX][MAX];
int MoveY[2] = { 0,1 };
int MoveX[2] = { 1,0 };

void input() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> MAP[i][j];
        }
    }
}

bool bfs() {
    queue<pair<int, int> > Q;
    Visited[0][0] = true;
    Q.push(make_pair(0, 0));

    while (!Q.empty()) {
        int NowY = Q.front().first;
        int NowX = Q.front().second;
        Q.pop();

        if ((NowY == M - 1) && (NowX == N - 1)) {
            return true;
        }

        for (int i = 0; i < 2; i++) {
            int NextY = NowY + MoveY[i];
            int NextX = NowX + MoveX[i];
            if ((NextY >= 0) && (NextY < M) && (NextX >= 0) && (NextX < N) && !Visited[NextY][NextX] && (MAP[NextY][NextX] == 1)) {
                Visited[NextY][NextX] = true;
                Q.push(make_pair(NextY, NextX));
            }
        }
    };

    return false;
}

void find_Answer() {
    if (bfs()) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }
}

int main() {
    FASTIO
    input();
    find_Answer();

    return 0;
}