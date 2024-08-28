#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, Min;
vector<int> A;
int Answer;

void input() {
    cin >> N;
    A.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    Min = A[0];
    for (int i = 1; i < N; i++) {
        if (A[i - 1] < A[i]) {
            Answer = max(Answer, A[i] - Min);
        }
        else {
            Min = A[i];
        }
    }
    cout << Answer << "\n";
}

int main() {
    FASTIO
    input();

    return 0;
}