#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MAX 11
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, M, I;
int MAP[MAX];
int Answer;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> MAP[i + 1];
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> I;
        Answer += MAP[I];
    }
    cout << Answer << "\n";
}

int main() {
    FASTIO
    input();

    return 0;
}