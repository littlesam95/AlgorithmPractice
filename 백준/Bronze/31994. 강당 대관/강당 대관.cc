#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
vector<pair<string, int> > Vec(7);

bool comp(pair<string, int> A, pair<string, int> B) {
    return (A.second > B.second);
}

void input() {
    for (int i = 0; i < 7; i++) {
        cin >> Vec[i].first >> Vec[i].second;
    }
    sort(Vec.begin(), Vec.end(), comp);
    cout << Vec[0].first << "\n";
}

int main() {
    FASTIO
    input();

    return 0;
}