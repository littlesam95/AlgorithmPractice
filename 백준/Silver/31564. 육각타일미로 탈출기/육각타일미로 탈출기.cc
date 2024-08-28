#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#define MAX 1001
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, M, K, YK, XK;
int MAP[MAX][MAX];
bool Visited[MAX][MAX];
int MoveY[2][6] = { { -1,-1,0,1,1,0 }, { -1,-1,0,1,1,0 } };
int MoveX[2][6] = { { -1,0,1,0,-1,-1 }, { 0,1,1,1,0,-1 } };
int Answer = -1;

void input() {
    cin >> N >> M >> K;
    for (int i = 0; i < K; i++) {
        cin >> YK >> XK;
        MAP[YK][XK] = -1;
    }
}

void bfs() {
    queue<pair<pair<int, int>, int> > Q;
    Visited[0][0] = true;
    Q.push(make_pair(make_pair(0, 0), 0));

    while (!Q.empty()) {
        int NowY = Q.front().first.first;
        int NowX = Q.front().first.second;
        int NowT = Q.front().second;
        Q.pop();

        if ((NowY == (N - 1)) && (NowX == (M - 1))) {
            Answer = NowT;
            return;
        }

        for (int i = 0; i < 6; i++) {
            int NextY = NowY + MoveY[NowY % 2][i];
            int NextX = NowX + MoveX[NowY % 2][i];
            if ((NextY >= 0) && (NextY < N) && (NextX >= 0) && (NextX < M) && !Visited[NextY][NextX] && (MAP[NextY][NextX] != -1)) {
                Visited[NextY][NextX] = true;
                Q.push(make_pair(make_pair(NextY, NextX), NowT + 1));
            }
        }
    };
}

void settings() {
    bfs();
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