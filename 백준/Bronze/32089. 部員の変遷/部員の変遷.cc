#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N;
vector<int> Vec;
int Answer;

void init() {
    Vec.clear();
    Answer = 0;
}

void settings() {
    for (int i = 2; i < N; i++) {
        Answer = max(Answer, Vec[i - 2] + Vec[i - 1] + Vec[i]);
    }
}

void find_Answer() {
    cout << Answer << "\n";
}

void input() {
    while (1) {
        init();
        cin >> N;
        if (N == 0) break;
        Vec.resize(N);
        for (int i = 0; i < N; i++) {
            cin >> Vec[i];
        }
        settings();
        find_Answer();
    };
}

int main() {
    FASTIO
    input();

    return 0;
}