#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MAX 301
#define INF 1e9
#define LL long long
#define FASTIO cin.tie(0); cout.tie(0);

using namespace std;
int N, M, T;
int Height[MAX][MAX];

void init() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) {
                continue;
            }
            Height[i][j] = INF;
        }
    }
}

void floyd_Warshall() {
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                int Next = max(Height[i][k], Height[k][j]);
                Height[i][j] = min(Height[i][j], Next);
            }
        }
    }
}

void input() {
    cin >> N >> M >> T;
    init();
    while (M--) {
        int S, E, H;
        cin >> S >> E >> H;;
        Height[S][E] = H;
    };
    floyd_Warshall();
    while (T--) {
        int A, B;
        cin >> A >> B;
        if (Height[A][B] == INF) {
            cout << "-1\n";
        }
        else {
            cout << Height[A][B] << "\n";
        }
    };
}

int main() {
    FASTIO
    input();

    return 0;
}