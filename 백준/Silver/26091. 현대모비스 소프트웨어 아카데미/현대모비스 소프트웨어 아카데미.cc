#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, M, L, R;
vector<int> Vec;
int Answer;

void input() {
    cin >> N >> M;
    Vec.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> Vec[i];
    }
}

void settings() {
    sort(Vec.begin(), Vec.end());
    R = N - 1;

    while (L < R) {
        int First = Vec[L];
        int Last = Vec[R];
        if (First + Last >= M) {
            Answer++;
            R--;
        }
        L++;
    };
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