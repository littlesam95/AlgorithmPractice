#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define LL long long
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, A, B;
vector<pair<LL, LL> > Vec;
LL Answer;

void input() {
    cin >> N >> A >> B;
    Vec.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> Vec[i].first >> Vec[i].second;
    }
}

bool Comp(pair<LL, LL> PA, pair<LL, LL> PB) {
    return ((PA.first - PA.second) < (PB.first - PB.second));
}

void settings() {
    sort(Vec.begin(), Vec.end(), Comp);
    for (int i = 0; i < A; i++) {
        Answer += Vec[i].first;
    }
    for (int i = A; i < N; i++) {
        Answer += Vec[i].second;
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