#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int P, N;
vector<int> A;
int Answer;

void input() {
    cin >> P >> N;
    A.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
}

void settings() {
    sort(A.begin(), A.end());
    for (int i = 0; i < N; i++) {
        if (P >= 200) {
            break;
        }
        P += A[i];
        Answer++;
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