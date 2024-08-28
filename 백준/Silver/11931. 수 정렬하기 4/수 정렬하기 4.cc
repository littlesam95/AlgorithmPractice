#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N;
vector<int> A;

void input() {
    cin >> N;
    A.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
}

bool comp(int A, int B) {
    return (A > B);
}

void settings() {
    sort(A.begin(), A.end(), comp);
}

void find_Answer() {
    for (int i = 0; i < N; i++) {
        cout << A[i] << "\n";
    }
}

int main() {
    FASTIO
    input();
    settings();
    find_Answer();

    return 0;
}