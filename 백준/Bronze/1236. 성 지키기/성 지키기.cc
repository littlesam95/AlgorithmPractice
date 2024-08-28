#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MAX 51
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, M;
string S;
char MAP[MAX][MAX];
int keeperN, keeperM;

void input() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> S;
        for (int j = 0; j < M; j++) {
            MAP[i][j] = S[j];
        }
    }
}

void settings() {
    keeperN = N;
    keeperM = M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (MAP[i][j] == 'X') {
                keeperN--;
                break;
            }
        }
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (MAP[j][i] == 'X') {
                keeperM--;
                break;
            }
        }
    }
}

void find_Answer() {
    if (N == 1) {
        cout << keeperM << "\n";
    }
    else if (M == 1){
        cout << keeperN << "\n";
    }
    else {
        cout << max(keeperN, keeperM) << "\n";
    }
}

int main() {
    FASTIO
    input();
    settings();
    find_Answer();

    return 0;
}