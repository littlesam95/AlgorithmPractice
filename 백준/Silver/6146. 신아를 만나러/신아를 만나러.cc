#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#define MAX 1001
#define INF 1e9
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int X, Y, N;
int MAP[MAX][MAX];
bool Visited[MAX][MAX];
int MoveY[4] = { -1,0,1,0 };
int MoveX[4] = { 0,-1,0,1 };
queue<pair<pair<int, int>, int> > Q;
int Answer = INF;

void input() {
    cin >> X >> Y >> N;
    MAP[X + 500][Y + 500] = 1;
    for (int i = 0; i < N; i++) {
        int A, B;
        cin >> A >> B;
        MAP[A + 500][B + 500] = -1;
    }
}

void BFS() {
    Visited[500][500] = true;
    Q.push(make_pair(make_pair(500, 500), 0));
    while (!Q.empty()) {
        int NowY = Q.front().first.first;
        int NowX = Q.front().first.second;
        int NowT = Q.front().second;
        Q.pop();

        if (MAP[NowY][NowX] == 1) {
            Answer = min(Answer, NowT);
            return;
        }

        for (int i = 0; i < 4; i++) {
            int NextY = NowY + MoveY[i];
            int NextX = NowX + MoveX[i];
            if ((NextY >= 0) && (NextY < MAX) && (NextX >= 0) && (NextX < MAX) && (MAP[NextY][NextX] != -1)) {
                if (!Visited[NextY][NextX]) {
                    Visited[NextY][NextX] = true;
                    Q.push(make_pair(make_pair(NextY, NextX), NowT + 1));
                }
            }
        }
    };
}

void settings() {
    BFS();
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