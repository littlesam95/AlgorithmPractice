#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MAX 117
#define ULL unsigned long long
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N;
ULL DP[MAX];

ULL dfs(int Now) {
    if (DP[Now] > 0) {
        return DP[Now];
    }

    return DP[Now] = dfs(Now - 1) + dfs(Now - 3);
}

void init() {
    DP[1] = 1;
    DP[2] = 1;
    DP[3] = 1;
    dfs(MAX - 1);
}

void input() {
    cin >> N;
}

void find_Answer() {
    cout << DP[N] << "\n";
}

int main() {
    FASTIO
    init();
    input();
    find_Answer();

    return 0;
}