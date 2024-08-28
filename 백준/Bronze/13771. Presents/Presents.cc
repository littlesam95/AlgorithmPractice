#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N;
vector<double> Vec;

void input() {
    cin >> N;
    Vec.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> Vec[i];
    }
    sort(Vec.begin(), Vec.end());
    cout << fixed;
    cout.precision(2);
    cout << Vec[1] << "\n";
}

int main() {
    FASTIO
    input();

    return 0;
}