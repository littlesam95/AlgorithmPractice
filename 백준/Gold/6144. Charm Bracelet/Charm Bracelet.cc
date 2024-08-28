#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define MAX_N 3403
#define MAX_M 12881

using namespace std;
int N, M;
int W[MAX_N], D[MAX_N];
int DP[MAX_M];

void input() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> W[i] >> D[i];
    }
}

void settings() {
    for (int i = 1; i <= N; i++) {
        for (int j = M; j >= 0; j--) {
            if (j - W[i] >= 0) {
                DP[j] = max(DP[j], DP[j - W[i]] + D[i]);
            }
        }
    }
}

void find_Answer() {
    int Answer = 0;
    for (int i = 0; i <= M; i++) {
        Answer = max(Answer, DP[i]);
    }
    cout << Answer << "\n";
}

int main() {
    input();
    settings();
    find_Answer();

    return 0;
}