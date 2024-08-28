#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, M, K, D, S;
priority_queue<int> PQ;
vector<int> Answer;

void input() {
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        cin >> D;
        PQ.push(D);
    }
}

void settings() {
    while (!PQ.empty()) {
        int top = PQ.top();
        PQ.pop();

        S = (S / 2) + top;
        Answer.push_back(S);
        top -= M;

        if (top > K) {
            PQ.push(top);
        }
    };
}

void find_Answer() {
    cout << (int)Answer.size() << "\n";
    for (int i = 0; i < (int)Answer.size(); i++) {
        cout << Answer[i] << "\n";
    }
}

int main() {
    FASTIO
    input();
    settings();
    find_Answer();

    return 0;
}