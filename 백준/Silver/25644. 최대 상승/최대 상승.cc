#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N;
vector<int> A;
int Max_A;
int Answer;

void input() {
    cin >> N;
    A.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
}

void settings() {
    for (int i = (N - 1); i >= 0; i--) {
        int Now = A[i];
        Max_A = max(Max_A, Now);
        Answer = max(Answer, Max_A - Now);
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