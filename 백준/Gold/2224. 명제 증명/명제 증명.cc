#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MAX 58
#define INF 1e9
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, M;
char A, B;
string IS;
int DP[MAX][MAX];
vector<string> X;

void init() {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (i == j) {
                continue;
            }
            DP[i][j] = INF;
        }
    }
}

void input() {
    cin >> N;
    while (N--) {
        cin >> A >> IS >> B;
        int X = A - 'A';
        int Y = B - 'A';
        DP[X][Y] = 1;
    };
}

void settings() {
    for (int k = 0; k < MAX; k++) {
        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++) {
                if (i == j) {
                    continue;
                }
                if (DP[i][j] > DP[i][k] + DP[k][j]) {
                    DP[i][j] = DP[i][k] + DP[k][j];
                }
            }
        }
    }
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (i == j) {
                continue;
            }
            if (DP[i][j] != INF) {
                char First = (char)(i + 65);
                char Second = (char)(j + 65);
                string Tmp = "";
                Tmp += First;
                Tmp += " => ";
                Tmp += Second;
                X.push_back(Tmp);
            }
        }
    }
}

void find_Answer() {
    cout << X.size() << "\n";
    for (int i = 0; i < X.size(); i++) {
        cout << X[i] << "\n";
    }
}

int main() {
    FASTIO
    init();
    input();
    settings();
    find_Answer();

    return 0;
}