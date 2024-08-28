#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#define MAX 10001
#define FASTIO cin.tie(0); cout.tie(0);

using namespace std;
int N, A, B;
vector<int> Vec;
bool visited[MAX];
int Answer = -1;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int I;
        cin >> I;
        Vec.push_back(I);
    }
    cin >> A >> B;
}

void settings() {
    A--; B--;

    queue<pair<int, int> > Q;
    Q.push(make_pair(A, 0));

    while(!Q.empty()) {
        int CurX = Q.front().first;
        int CurC = Q.front().second;
        Q.pop();

        visited[CurX] = true;
        if (CurX == B) {
            Answer = CurC;
            return;
        }

        int CurN = Vec[CurX];
        for (int i = 1; i <= 10000; i++) {
            int Next = CurX + (CurN * i);
            int Prev = CurX - (CurN * i);
            if ((Prev < 0) && (Next >= N)) {
                break;
            }
            if ((Next >= 0) && (Next < N)) {
                if (!visited[Next]) {
                    Q.push(make_pair(Next, CurC + 1));
                }
            }
            if ((Prev >= 0) && (Prev < N)) {
                if (!visited[Prev]) {
                    Q.push(make_pair(Prev, CurC + 1));
                }
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