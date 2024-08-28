#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MAX 11
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N;
int DP[MAX];

void input() {
    cin >> N;
}

int dfs(int Now) {
    if (Now == 1) {
        return 0;
    }

    for (int i = (Now - 1); i > 0; i--) {
        DP[Now] = max(DP[Now], i * (Now - i) + dfs(i) + dfs(Now - i));
    }

    return DP[Now];
}

void settings() {
    DP[N] = dfs(N);
}

void find_Answer() {
    cout << DP[N] << "\n";
}

int main() {
    FASTIO
    input();
    settings();
    find_Answer();

    return 0;
}