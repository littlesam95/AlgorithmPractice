#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int T, N, L;
string S;
vector<pair<string, int> > Vec;

bool comp(pair<string, int> A, pair<string, int> B) {
    return (A.second > B.second);
}

void input() {
    cin >> T;
    while (T--) {
        Vec.clear();
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> S >> L;
            Vec.push_back(make_pair(S, L));
        }
        sort(Vec.begin(), Vec.end(), comp);
        cout << (*Vec.begin()).first << "\n";
    };
}

int main() {
    FASTIO
    input();

    return 0;
}