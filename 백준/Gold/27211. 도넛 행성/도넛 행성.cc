#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#define MAX 1001
#define INF 1e9
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, M;
int MAP[MAX][MAX];
bool Visited[MAX][MAX];
int MoveY[4] = { -1,0,1,0 };
int MoveX[4] = { 0,-1,0,1 };
int Answer = 0;

void input() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> MAP[i][j];
        }
    }
}

void BFS(int Y, int X) {
    queue<pair<int, int> > Q;
    Visited[Y][X] = true;
    Q.push(make_pair(Y, X));
    
    while (!Q.empty()) {
        int NowY = Q.front().first;
        int NowX = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int NextY = NowY + MoveY[i];
            if (NextY < 0) {
                NextY = N - 1;
            }
            else if (NextY >= N) {
                NextY = 0;
            }
            int NextX = NowX + MoveX[i];
            if (NextX < 0) {
                NextX = M - 1;
            }
            else if (NextX >= M) {
                NextX = 0;
            }
            if (!Visited[NextY][NextX] && (MAP[NextY][NextX] == 0)) {
                Visited[NextY][NextX] = true;
                Q.push(make_pair(NextY, NextX));
            }
        }
    };
}

void settings() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if ((MAP[i][j] == 0) && !Visited[i][j]) {
                BFS(i, j);
                Answer++;
            }
        }
    }
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