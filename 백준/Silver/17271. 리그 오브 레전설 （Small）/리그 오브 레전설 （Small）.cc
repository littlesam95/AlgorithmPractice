#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MAX 10001
#define MOD 1000000007
#define LL long long
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, M;
LL DP[MAX];

void input() {
    cin >> N >> M;
}

void settings() {
    for (int i = 1; i < M; i++) {
        DP[i] = 1;
    }
    DP[M] = 2;
    for (int i = (M + 1); i <= N; i++) {
        DP[i] = ((DP[i - 1] % MOD) + (DP[i - M] % MOD)) % MOD;
    }
}

void find_Answer() {
    cout << (DP[N] % MOD) << "\n";
}

int main() {
    FASTIO
    input();
    settings();
    find_Answer();

    return 0;
}