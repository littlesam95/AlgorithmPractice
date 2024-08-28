#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MAX 11
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N;
int W[MAX], Prev[MAX], Next[MAX];
bool Visited[MAX];
int Answer;

void init() {
    for (int i = 1; i < MAX; i++) {
        Prev[i] = i - 1;
        Next[i] = i + 1;
    }
}

void input() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> W[i];
    }
}

void dfs(int Depth, int Sum) {
    if (Depth == (N - 2)) {
        Answer = max(Answer, Sum);
        return;
    }

    for (int i = 2; i < N; i++) {
        if (!Visited[i]) {
            int PrevX = Prev[i];
            int NextX = Next[i];
            int Energe = (W[PrevX] * W[NextX]);
            Visited[i] = true;
            Prev[NextX] = PrevX;
            Next[PrevX] = NextX;
            dfs(Depth + 1, Sum + Energe);
            Next[PrevX] = i;
            Prev[NextX] = i;
            Visited[i] = false;
        }
    }
}

void settings() {
    dfs(0, 0);
}

void find_Answer() {
    cout << Answer << "\n";
}

int main() {
    FASTIO
    init();
    input();
    settings();
    find_Answer();

    return 0;
}