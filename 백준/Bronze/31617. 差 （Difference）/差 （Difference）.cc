#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MAX 101
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int K, N, M;
int A[MAX], B[MAX];
int Answer;

void input() {
    cin >> K;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }
    for (int i = 0; i < N; i++) {
        int P = A[i];
        for (int j = 0; j < M; j++) {
            int Q = B[j];
            if (A[i] + K == B[j]) {
                Answer++;
            }
        }
    }
    cout << Answer << "\n";
}

int main() {
    FASTIO
    input();

    return 0;
}