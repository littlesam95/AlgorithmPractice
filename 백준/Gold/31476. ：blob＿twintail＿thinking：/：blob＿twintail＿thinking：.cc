#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <algorithm>
#define MAX 5000
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int D, N, U, T, S, E, Cnt;
bool Banned[MAX][2];
bool Visited[MAX];
int AnswerT, AnswerP;

void input() {
    cin >> D >> N >> U >> T;
    for (int i = 0; i < N; i++) {
        cin >> S >> E;
        if ((S * 2) == E) {
            Banned[S][0] = true;
        }
        else {
            Banned[S][1] = true;
        }
    }
}

void twiintail() {
    queue<pair<pair<int, int>, pair<int, int> > > Q;
    Visited[1] = true;
    Q.push(make_pair(make_pair(1, 1), make_pair(0, 0)));

    while (!Q.empty()) {
        int NowX = Q.front().first.first;
        int NowD = Q.front().first.second;
        int NowS = Q.front().second.first;
        int NowT = Q.front().second.second;
        Q.pop();

        Cnt++;
        AnswerT = max(AnswerT, NowT);

        if (NowD == D) {
            continue;
        }

        if (!Banned[NowX][0] && !Banned[NowX][1]) {
            Q.push(make_pair(make_pair(NowX * 2, NowD + 1), make_pair(NowS + 1, NowT + U + (T * (NowS + 1)))));
            Q.push(make_pair(make_pair((NowX * 2) + 1, NowD + 1), make_pair(NowS + 1, NowT + U + (T * (NowS + 1)))));
        }
        else if (!Banned[NowX][0] && Banned[NowX][1]) {
            Q.push(make_pair(make_pair(NowX * 2, NowD + 1), make_pair(NowS, NowT + U + (T * NowS))));
        }
        else if (Banned[NowX][0] && !Banned[NowX][1]) {
            Q.push(make_pair(make_pair((NowX * 2) + 1, NowD + 1), make_pair(NowS, NowT + U + (T * NowS))));
        }
    };
}

void ponytail(int Depth, int Now) {
    Cnt--;

    if (Depth == D) {
        return;
    }

    if (!Banned[Now][0] && !Visited[Now * 2]) {
        Visited[Now * 2] = true;
        AnswerP += U;
        ponytail(Depth + 1, Now * 2);
        if (Cnt > 0) {
            AnswerP += U;
        }
    }
    if (!Banned[Now][1] && !Visited[(Now * 2) + 1]) {
        Visited[(Now * 2) + 1] = true;
        AnswerP += U;
        ponytail(Depth + 1, (Now * 2) + 1);
        if (Cnt > 0) {
            AnswerP += U;
        }
    }
}

void settings() {
    twiintail();
    ponytail(1, 1);
}

void find_Answer() {
    if (AnswerT < AnswerP) {
        cout << ":blob_twintail_aww:\n";
    }
    else if (AnswerT > AnswerP) {
        cout << ":blob_twintail_sad:\n";
    }
    else {
        cout << ":blob_twintail_thinking:\n";
    }
}

int main() {
    FASTIO
    input();
    settings();
    find_Answer();

    return 0;
}