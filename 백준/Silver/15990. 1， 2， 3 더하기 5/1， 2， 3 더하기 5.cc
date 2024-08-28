#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MAX 1000001
#define MOD 1000000009
#define LL long long
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int T, N;
LL DP[MAX][4];

void init() {
    DP[1][1] = 1;
    DP[2][2] = 1;
    DP[3][1] = 1;
    DP[3][2] = 1;
    DP[3][3] = 1;
    for (int i = 4; i < MAX; i++) {
        DP[i][1] = ((DP[i - 1][2] % MOD) + (DP[i - 1][3] % MOD)) % MOD;
        DP[i][2] = ((DP[i - 2][1] % MOD) + (DP[i - 2][3] % MOD)) % MOD;
        DP[i][3] = ((DP[i - 3][1] % MOD) + (DP[i - 3][2] % MOD)) % MOD;
    }
}

void find_Answer() {
    cout << ((DP[N][1] % MOD) + (DP[N][2] % MOD) + (DP[N][3] % MOD)) % MOD << "\n";
}

void input() {
    cin >> T;
    while (T--) {
        cin >> N;
        find_Answer();
    }
}

int main() {
    FASTIO
    init();
    input();

    return 0;
}