#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#define MAX 100001
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, M, A, B, X;
int Train[MAX];
set<int> Answer;

void input() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> A >> B;
        if (A == 1) {
            cin >> X;
            X--;
            Train[B] |= (1 << X);
        }
        else if (A == 2) {
            cin >> X;
            X--;
            Train[B] &= ~(1 << X);
        }
        else if (A == 3) {
            Train[B] <<= 1;
            Train[B] &= ~(1 << 20);
        }
        else if (A == 4) {
            Train[B] >>= 1;
        }
    }
    for (int i = 1; i <= N; i++) {
        Answer.insert(Train[i]);
    }
}

void find_Answer() {
    cout << (int)Answer.size() << "\n";
}

int main() {
    FASTIO
    input();
    find_Answer();

    return 0;
}