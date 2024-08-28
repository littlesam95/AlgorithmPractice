#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, A, B;
priority_queue<int> PQ;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A;
        if (A == 0) {
            if (PQ.empty()) {
                cout << "-1\n";
            }
            else {
                cout << PQ.top() << "\n";
                PQ.pop();
            }
        }
        else {
            for (int j = 0; j < A; j++) {
                cin >> B;
                PQ.push(B);
            }
        }
    }
}

int main() {
    FASTIO
    input();

    return 0;
}