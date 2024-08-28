#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#define MAX 100001
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, M, T, X, Y, C;
vector<int> Edge[MAX];
vector<int> reverse_Edge[MAX];
bool Visited[2][MAX];

void bfs() {
    queue<pair<int, bool> > Q;
    Visited[0][1] = true;
    Visited[1][N] = true;
    Q.push(make_pair(1, false));
    Q.push(make_pair(N, true));

    while (!Q.empty()) {
        int NowX = Q.front().first;
        bool isReversed = Q.front().second;
        Q.pop();

        if (isReversed) {
            for (int i = 0; i < (int)reverse_Edge[NowX].size(); i++) {
                int NextX = reverse_Edge[NowX][i];
                if (!Visited[isReversed][NextX]) {
                    Visited[isReversed][NextX] = true;
                    Q.push(make_pair(NextX, isReversed));
                }
            }
        }
        else {
            for (int i = 0; i < (int)Edge[NowX].size(); i++) {
                int NextX = Edge[NowX][i];
                if (!Visited[isReversed][NextX]) {
                    Visited[isReversed][NextX] = true;
                    Q.push(make_pair(NextX, isReversed));
                }
            }
        }
    };
}

void settings() {
    bfs();
}

void find_Answer() {
    if (Visited[0][C] && Visited[1][C]) {
        cout << "Defend the CTP\n";
    }
    else {
        cout << "Destroyed the CTP\n";
    }
}

void input() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> X >> Y;
        Edge[X].push_back(Y);
        reverse_Edge[Y].push_back(X);
    }
    settings();
    cin >> T;
    while (T--) {
        cin >> C;
        find_Answer();
    };
}

int main() {
    FASTIO
    input();

    return 0;
}