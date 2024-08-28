#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MAX 11
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, K;
int A[MAX], B[MAX], C[MAX];
bool Visited[MAX];
int Answer = -1;

void input() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }
}

void dfs(int Depth, int PrevA, int PrevC, int Sum) {
    if (Depth == N) {
        Answer = max(Answer, Sum);
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!Visited[i] && (PrevC * C[i] <= K)) {
            Visited[i] = true;
            dfs(Depth + 1, A[i], C[i], Sum + (PrevA * B[i]));
            Visited[i] = false;
        }
    }
}

void settings() {
    for (int i = 0; i < N; i++) {
        Visited[i] = true;
        dfs(1, A[i], C[i], 0);
        Visited[i] = false;
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