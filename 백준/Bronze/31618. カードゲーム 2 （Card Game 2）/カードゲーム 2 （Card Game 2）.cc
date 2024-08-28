#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, M;
set<int> S;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> M;
        S.insert(M);
    }
    for (auto IT : S) {
        int X = IT;
        if ((S.find(X + 3) != S.end()) && (S.find(X + 6) != S.end())) {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
}

int main() {
    FASTIO
    input();

    return 0;
}