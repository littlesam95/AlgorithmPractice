#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#define MAX 101
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, M, X;
int MAP[MAX][MAX];
bool Visited[MAX][MAX];
int MoveY[4] = { -1,0,1,0 };
int MoveX[4] = { 0,-1,0,1 };
int ManhattanY[4] = { 1,1,-1,-1 };
int ManhattanX[4] = { -1,1,1,-1 };

void input() {
    cin >> N;
    cin >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> MAP[i][j];
        }
    }
    cin >> X;
}

bool bfs() {
    queue<pair<int, int> > Q;
    Q.push(make_pair(0, 0));
    Visited[0][0] = true;

    while (!Q.empty()) {
        int NowY = Q.front().first;
        int NowX = Q.front().second;
        Q.pop();

        if ((NowY == (N - 1)) && (NowX == (M - 1))) {
            return true;
        }

        for (int i = 1; i <= X; i++) {
            for (int j = 0; j < 4; j++) {
                int NextY = NowY + (MoveY[j] * i);
                int NextX = NowX + (MoveX[j] * i);
                
                for (int k = 0; k < i; k++) {
                    int NNextY = NextY + (ManhattanY[j] * k);
                    int NNextX = NextX + (ManhattanX[j] * k);
                    if ((NNextY >= 0) && (NNextY < N) && (NNextX >= 0) && (NNextX < M) && !Visited[NNextY][NNextX] && (MAP[NNextY][NNextX] == MAP[NowY][NowX])) {
                        Q.push(make_pair(NNextY, NNextX));
                        Visited[NNextY][NNextX] = true;
                    }
                }
            }
        }
    };

    return false;
}

void find_Answer() {
    if (bfs()) {
        cout << "ALIVE\n";
    }
    else {
        cout << "DEAD\n";
    }
}

int main() {
    FASTIO
    input();
    find_Answer();

    return 0;
}