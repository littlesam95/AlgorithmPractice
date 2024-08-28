#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <algorithm>
#define MAX 51
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, M, K;
string Name;
unordered_map<int, string> UM;
int MAP[MAX][5][5];
set<int> S;
set<int> Answer;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> Name;
        UM[i] = Name;
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                cin >> MAP[i][j][k];
            }
        }
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> K;
        S.insert(K);
    }
}

bool isCalled(int Number) {
    if (S.find(Number) != S.end()) {
        return true;
    }

    return false;
}

void settings() {
    for (int i = 0; i < N; i++) {
        if (Answer.find(i) != Answer.end()) {
            continue;
        }
        for (int j = 0; j < 5; j++) {
            if (isCalled(MAP[i][j][0]) && isCalled(MAP[i][j][1]) && isCalled(MAP[i][j][2]) && isCalled(MAP[i][j][3]) && isCalled(MAP[i][j][4])) {
                Answer.insert(i);
                break;
            }
        }

        if (Answer.find(i) != Answer.end()) {
            continue;
        }
        for (int j = 0; j < 5; j++) {
            if (isCalled(MAP[i][0][j]) && isCalled(MAP[i][1][j]) && isCalled(MAP[i][2][j]) && isCalled(MAP[i][3][j]) && isCalled(MAP[i][4][j])) {
                Answer.insert(i);
                break;
            }
        }

        if (Answer.find(i) != Answer.end()) {
            continue;
        }
        if (isCalled(MAP[i][0][0]) && isCalled(MAP[i][1][1]) && isCalled(MAP[i][2][2]) && isCalled(MAP[i][3][3]) && isCalled(MAP[i][4][4])) {
            Answer.insert(i);
        }

        if (Answer.find(i) != Answer.end()) {
            continue;
        }
        if (isCalled(MAP[i][0][4]) && isCalled(MAP[i][1][3]) && isCalled(MAP[i][2][2]) && isCalled(MAP[i][3][1]) && isCalled(MAP[i][4][0])) {
            Answer.insert(i);
        }
    }
}

void find_Answer() {
    cout << (int)Answer.size() << "\n";
    for (auto IT : Answer) {
        cout << UM[IT] << "\n";
    }
}

int main() {
    FASTIO
    input();
    settings();
    find_Answer();

    return 0;
}