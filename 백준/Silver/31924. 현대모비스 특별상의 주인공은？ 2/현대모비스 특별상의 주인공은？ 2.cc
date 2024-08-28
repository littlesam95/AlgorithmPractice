#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MAX 101
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N;
char MAP[MAX][MAX];
int MoveY[8] = { -1,-1,-1,0,1,1,1,0 };
int MoveX[8] = { -1,0,1,1,1,0,-1,-1 };
int Answer;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        string S;
        cin >> S;
        for (int j = 0; j < N; j++) {
            MAP[i][j] = S[j];
        }
    }
}

void settings() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < 8; k++) {
                if ((i + (MoveY[k] * 4) >= 0) && (i + (MoveY[k] * 4) < N) && (j + (MoveX[k] * 4) >= 0) && (j + (MoveX[k] * 4) < N)) {
                    if ((MAP[i][j] == 'M') && (MAP[i + MoveY[k]][j + MoveX[k]] == 'O') && (MAP[i + (MoveY[k] * 2)][j + (MoveX[k] * 2)] == 'B') && (MAP[i + (MoveY[k] * 3)][j + (MoveX[k] * 3)] == 'I') && (MAP[i + (MoveY[k] * 4)][j + (MoveX[k] * 4)] == 'S')) {
                        Answer++;
                    }
                }
            }
        }
    }
}

void find_Answer() {
    cout << Answer << "\n";
}

int main() {
    FASTIO
    input();
    settings();
    find_Answer();

    return 0;
}