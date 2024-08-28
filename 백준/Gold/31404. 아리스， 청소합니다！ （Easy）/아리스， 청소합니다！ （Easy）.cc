#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#define MAX 65
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int H, W, R, C, D;
int MAP[MAX][MAX], A[MAX][MAX], B[MAX][MAX];
bool Visited[MAX][MAX][4];
int MoveY[4] = { -1,0,1,0 };
int MoveX[4] = { 0,1,0,-1 };
int Answer;

void input() {
    cin >> H >> W;
    cin >> R >> C >> D;
    for (int i = 0; i < H; i++) {
        string S;
        cin >> S;
        for (int j = 0; j < W; j++) {
            A[i][j] = (S[j] - '0');
        }
    }
    for (int i = 0; i < H; i++) {
        string S;
        cin >> S;
        for (int j = 0; j < W; j++) {
            B[i][j] = (S[j] - '0');
        }
    }
}

void init_Position() {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            for (int k = 0; k < 4; k++) {
                Visited[i][j][k] = false;
            }
        }
    }
}

void settings() {
    queue<pair<pair<int, int>, pair<int, pair<int, int> > > > Q;
    Q.push(make_pair(make_pair(R, C), make_pair(D, make_pair(0, 0))));

    while (!Q.empty()) {
        int NowY = Q.front().first.first;
        int NowX = Q.front().first.second;
        int NowD = Q.front().second.first;
        int NowT = Q.front().second.second.first;
        int NowC = Q.front().second.second.second;
        Q.pop();

        if (MAP[NowY][NowX] == 0) {
            MAP[NowY][NowX] = 1;
            init_Position();
            int NextD = ((NowD + A[NowY][NowX]) % 4);
            int NextY = NowY + MoveY[NextD];
            int NextX = NowX + MoveX[NextD];
            if ((NextY < 0) || (NextY >= H) || (NextX < 0) || (NextX >= W)) {
                Answer = (NowT + 1);
                return;
            }
            Q.push(make_pair(make_pair(NextY, NextX), make_pair(NextD, make_pair(NowT + 1, 0))));
        }
        else {
            if (!Visited[NowY][NowX][NowD]) {
                Visited[NowY][NowX][NowD] = true;
                int NextD = ((NowD + B[NowY][NowX]) % 4);
                int NextY = NowY + MoveY[NextD];
                int NextX = NowX + MoveX[NextD];
                if ((NextY < 0) || (NextY >= H) || (NextX < 0) || (NextX >= W)) {
                    Answer = (NowT - NowC);
                    return;
                }
                Q.push(make_pair(make_pair(NextY, NextX), make_pair(NextD, make_pair(NowT + 1, NowC + 1))));
            }
            else {
                Answer = (NowT - NowC);
                return;
            }
        }
    };
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