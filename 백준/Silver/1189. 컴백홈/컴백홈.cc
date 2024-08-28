#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MAX 6
#define FASTIO cin.tie(0); cout.tie(0);

using namespace std;
int R, C, K;
int MAP[MAX][MAX];
bool visited[MAX][MAX];
int MoveY[4] = { -1,0,1,0 };
int MoveX[4] = { 0,-1,0,1 };
int Answer = 0;

void input() {
    cin >> R >> C >> K;
    for (int i = 0; i < R; i++) {
        string S;
        cin >> S;
        for (int j = 0; j < C; j++) {
            if (S[j] == '.') {
                MAP[i][j] = 0;
            }
            else if (S[j] == 'T') {
                MAP[i][j] = -1;
            }
        }
    }
    MAP[0][C - 1] = 1;
    visited[R - 1][0] = true;
}

bool isAble(int Y, int X) {
    if ((Y >= 0) && (Y < R) && (X >= 0) && (X < C)) {
        return true;
    }
    return false;
}

void DFS(int Depth, int Y, int X) {
    if (Depth == K - 1) {
        if (MAP[Y][X] == 1) {
            Answer++;
        }
        return;
    }

    for (int i = 0; i < 4; i++) {
        int NextY = Y + MoveY[i];
        int NextX = X + MoveX[i];
        if (isAble(NextY, NextX) && (MAP[NextY][NextX] != -1) && !visited[NextY][NextX]) {
            visited[NextY][NextX] = true;
            DFS(Depth + 1, NextY, NextX);
            visited[NextY][NextX] = false;
        }
    }
}

void find_Answer() {
    cout << Answer << "\n";
}

int main() {
    FASTIO
    input();
    DFS(0, R - 1, 0);
    find_Answer();

    return 0;
}