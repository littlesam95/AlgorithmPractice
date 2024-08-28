#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, M, X;
unordered_map<int, int> UM;
vector<pair<int, int> > Vec;

bool comp(pair<int, int> A, pair<int, int> B) {
    if (A.second == B.second) {
        return (A.first < B.first);
    }

    return (A.second > B.second);
}

void input() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> X;
            if (X == 1) {
                UM[j + 1]++;
            }
        }
    }
    for (int i = 0; i < M; i++) {
        Vec.push_back(make_pair(i + 1, UM[i + 1]));
    }
    sort(Vec.begin(), Vec.end(), comp);
    for (int i = 0; i < M; i++) {
        cout << Vec[i].first << " ";
    }
    cout << "\n";
}

int main() {
    FASTIO
    input();

    return 0;
}