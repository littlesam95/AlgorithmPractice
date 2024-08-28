#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N;
vector<pair<string, int> > Vec;

bool comp(pair<string, int> A, pair<string, int> B) {
    if (A.second == B.second) {
        return (A.first < B.first);
    }

    return (A.second > B.second);
}

void input() {
    cin >> N;
    Vec.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> Vec[i].first >> Vec[i].second;
    }
    sort(Vec.begin(), Vec.end(), comp);
    cout << (*Vec.begin()).first << "\n";
}

int main() {
    FASTIO
    input();

    return 0;
}