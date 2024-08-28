#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, K;
vector<int> A;

void input() {
    cin >> N >> K;
    A.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
}

void settings() {
    sort(A.begin(), A.end());
}

void find_Answer() {
    cout << A[K - 1] << "\n";
}

int main() {
    FASTIO
    input();
    settings();
    find_Answer();

    return 0;
}