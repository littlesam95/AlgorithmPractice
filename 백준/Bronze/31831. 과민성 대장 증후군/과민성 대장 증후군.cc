#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#define MAX 100000
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, M;
int A[MAX];
int Sum[MAX];
int Answer;

void input() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
}

void settings() {
    Sum[0] = A[0];
    if (Sum[0] < 0) {
        Sum[0] = 0;
    }
    for (int i = 1; i < N; i++) {
        Sum[i] = max(Sum[i - 1] + A[i], 0);
    }
    for (int i = 0; i < N; i++) {
        if (Sum[i] >= M) {
            Answer++;
        }
    }
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