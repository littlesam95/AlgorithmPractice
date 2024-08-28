#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, A;
vector<int> Vec;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A;
        Vec.push_back(A);
    }
    sort(Vec.begin(), Vec.end());
    Vec.erase(unique(Vec.begin(), Vec.end()), Vec.end());
    for (int i = 0; i < (int)Vec.size(); i++) {
        cout << Vec[i] << "\n";
    }
}

int main() {
    FASTIO
    input();

    return 0;
}