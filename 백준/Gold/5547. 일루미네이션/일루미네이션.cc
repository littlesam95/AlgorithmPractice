#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#define MAX 101
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int W, H;
int MAP[MAX][MAX];
int adjacent[MAX][MAX][2];
bool Visited[MAX][MAX];
int MoveY[2][6] = { { -1,-1,0,1,1,0 }, { -1,-1,0,1,1,0 } };
int MoveX[2][6] = { { 0,1,1,1,0,-1 }, { -1,0,1,0,-1,-1 } };
int Answer;

void input() {
    cin >> W >> H;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> MAP[i][j];
        }
    }
}

int bfs(int Y, int X, int V) {
    queue<pair<int, int> > Q;
    Visited[Y][X] = true;
    Q.push(make_pair(Y, X));
    int Result = 0;

    while (!Q.empty()) {
        int NowY = Q.front().first;
        int NowX = Q.front().second;
        Q.pop();

        if (Result != -1) {
            Result += adjacent[NowY][NowX][!V];
        }

        for (int i = 0; i < 6; i++) {
            int NextY = NowY + MoveY[NowY % 2][i];
            int NextX = NowX + MoveX[NowY % 2][i];
            if ((NextY >= 0) && (NextY < H) && (NextX >= 0) && (NextX < W)) {
                if (!Visited[NextY][NextX] && (MAP[NextY][NextX] == V)) {
                    Visited[NextY][NextX] = true;
                    Q.push(make_pair(NextY, NextX));
                }
            }
            else {
                if (V == 0) {
                    Result = -1;
                }
            }
        }
    };

    if (Result == -1) {
        Result = 0;
    }

    return Result;
}

void settings() {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            for (int k = 0; k < 6; k++) {
                int NextY = i + MoveY[i % 2][k];
                int NextX = j + MoveX[i % 2][k];
                if ((NextY >= 0) && (NextY < H) && (NextX >= 0) && (NextX < W)) {
                    if (MAP[NextY][NextX] == 1) {
                        adjacent[i][j][1]++;
                    }
                    else {
                        adjacent[i][j][0]++;
                    }
                }
                else {
                    adjacent[i][j][0]++;
                }
            }
        }
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (!Visited[i][j]) {
                if (MAP[i][j] == 1) {
                    Answer += bfs(i, j, 1);
                }
                else {
                    Answer -= bfs(i, j, 0);
                }
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