#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MAX 101
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, M;
int MAP[MAX][MAX];

void input() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string S;
        cin >> S;
        for (int j = 0; j < M; j++) {
            if (S[j] == 'O') {
                MAP[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < M; i++) {
        bool Flag = true;
        for (int j = 0; j < N; j++) {
            if (MAP[j][i] == 1) {
                Flag = false;
                break;
            }
        }
        if (Flag) {
            cout << i + 1 << "\n";
            return;
        }
    }
    cout << "ESCAPE FAILED\n";
}

int main() {
    FASTIO
    input();

    return 0;
}