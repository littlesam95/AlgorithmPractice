#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, M, L, R;
vector<string> Files;

void input() {
    cin >> N;
    Files.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> Files[i];
    }
    cin >> M;
    while (M--) {
        cin >> L >> R;
        L--;
        R--;
        for (int i = L; i <= R; i++) {
            cout << Files[i] << "\n";
        }
    };
}

int main() {
    FASTIO
    input();

    return 0;
}