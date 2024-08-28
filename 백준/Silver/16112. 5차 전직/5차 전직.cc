#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define LL long long
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, K;
LL A, Exp;
vector<LL> Quest;
LL Answer;

void input() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> A;
        Quest.push_back(A);
    }
}

void settings() {
    sort(Quest.begin(), Quest.end());
    for (int i = 0; i < K; i++) {
        Answer += (Quest[i] * i);
    }
    for (int i = K; i < N; i++) {
        Answer += (Quest[i] * K);
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