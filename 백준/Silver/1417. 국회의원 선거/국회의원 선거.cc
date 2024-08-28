#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, M, Dasom;
priority_queue<int> PQ;
int Answer;

void input() {
    cin >> N;
    cin >> Dasom;
    for (int i = 0; i < (N - 1); i++) {
        cin >> M;
        PQ.push(M);
    }
}

void settings() {
    if (PQ.empty()) {
        return;
    }
    while (PQ.top() >= Dasom) {
        int Top = PQ.top();
        PQ.pop();
        Top--;
        Dasom++;
        Answer++;
        PQ.push(Top);
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