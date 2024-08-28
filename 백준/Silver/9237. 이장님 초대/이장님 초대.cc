#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define LL long long
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N;
vector<int> Vec;
int Answer;

bool comp(int A, int B) {
    return (A > B);
}

void input() {
    cin >> N;
    Vec.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> Vec[i];
    }
    sort(Vec.begin(), Vec.end(), comp);
    for (int i = 2; i < (N + 2); i++) {
        Answer = max(Answer, Vec[i - 2] + i);
    }
    cout << Answer << "\n";
}

int main() {
    FASTIO
    input();

    return 0;
}