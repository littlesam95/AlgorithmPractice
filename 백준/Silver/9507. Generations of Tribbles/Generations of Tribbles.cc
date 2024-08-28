#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MAX 68
#define ULL unsigned long long
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int T, N;
ULL DP[MAX];

ULL dfs(int Now) {
    if (DP[Now] != 0) {
        return DP[Now];
    }

    return DP[Now] = dfs(Now - 1) + dfs(Now - 2) + dfs(Now - 3) + dfs(Now - 4);
}

void init() {
    for (int i = 0; i < 2; i++) {
        DP[i] = 1;
    }
    DP[2] = 2;
    DP[3] = 4;
    dfs(MAX - 1);
}

void find_Answer() {
    cout << DP[N] << "\n";
}

void input() {
    cin >> T;
    while (T--) {
        cin >> N;
        find_Answer();
    };
}

int main() {
    FASTIO
    init();
    input();

    return 0;
}