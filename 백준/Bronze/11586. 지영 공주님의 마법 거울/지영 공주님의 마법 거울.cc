#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, K;
vector<string> Vec;

void input() {
    cin >> N;
    Vec.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> Vec[i];
    }
    cin >> K;

    if (K == 2) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < (N / 2); j++) {
                swap(Vec[i][j], Vec[i][N - 1 - j]);
            }
        }
    }
    else if (K == 3) {
        for (int i = 0; i < (N / 2); i++) {
            swap(Vec[i], Vec[N - 1 - i]);
        }
    }
    for (int i = 0; i < N; i++) {
        cout << Vec[i] << "\n";
    }
}

int main() {
    FASTIO
    input();

    return 0;
}