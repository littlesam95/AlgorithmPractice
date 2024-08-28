#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N;
vector<int> Vec;

void input() {
    cin >> N;
    Vec.resize(N + 1);
    Vec[0] = 0;
    for (int i = 1; i <= N; i++) {
        cin >> Vec[i];
    }
    sort(Vec.begin(), Vec.end());
    for (int i = 1; i <= N; i++) {
        if (Vec[i - 1] + 1 < Vec[i]) {
            cout << Vec[i - 1] + 1 << "\n";
            return;
        }
    }
    cout << Vec[N] + 1 << "\n";
}

int main() {
    FASTIO
    input();

    return 0;
}