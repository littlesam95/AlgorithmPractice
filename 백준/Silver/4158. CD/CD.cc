#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, M, X;
unordered_map<int, int> UM;
int Answer;

void input() {
    while (1) {
        UM.clear();
        Answer = 0;
        cin >> N >> M;
        if ((N == 0) && (M == 0)) {
            break;
        }
        for (int i = 0; i < N; i++) {
            cin >> X;
            UM[X] = 1;
        }
        for (int i = 0; i < M; i++) {
            cin >> X;
            if (UM[X] == 1) {
                Answer++;
            }
        }
        cout << Answer << "\n";
    };
}

int main() {
    FASTIO
    input();

    return 0;
}