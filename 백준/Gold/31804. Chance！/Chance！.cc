#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#define MAX 1000001
#define INF 2e9
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int A, B;
bool Visited[MAX][2];
int Answer = INF;

void input() {
    cin >> A >> B;
}

void bfs() {
    queue<pair<pair<int, int>, bool> > Q;
    Q.push(make_pair(make_pair(A, 0), false));
    Visited[A][0] = true;

    while (!Q.empty()) {
        int NowS = Q.front().first.first;
        int NowM = Q.front().first.second;
        bool isChanceUsed = Q.front().second;
        Q.pop();

        if (NowS == B) {
            Answer = min(Answer, NowM);
            continue;
        }

        if ((NowS + 1 <= B) && !Visited[NowS + 1][isChanceUsed]) {
            Q.push(make_pair(make_pair(NowS + 1, NowM + 1), isChanceUsed));
            Visited[NowS + 1][isChanceUsed] = true;
        }
        if ((NowS * 2 <= B) && !Visited[NowS * 2][isChanceUsed]) {
            Q.push(make_pair(make_pair(NowS * 2, NowM + 1), isChanceUsed));
            Visited[NowS * 2][isChanceUsed] = true;
        }
        if (!isChanceUsed && (NowS * 10 <= B) && !Visited[NowS * 10][isChanceUsed]) {
            Q.push(make_pair(make_pair(NowS * 10, NowM + 1), true));
            Visited[NowS * 10][isChanceUsed] = true;
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