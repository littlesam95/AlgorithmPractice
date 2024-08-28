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
LL DP[MAX];

void init() {
    DP[1] = 1;
    DP[2] = 2;
    DP[3] = 4;
    for (int i = 4; i < MAX; i++) {
        DP[i] = ((DP[i - 1] % MOD) + (DP[i - 2] % MOD) + (DP[i - 3] % MOD)) % MOD;
    }
}

void find_Answer() {
    cout << DP[N] % MOD << "\n";
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