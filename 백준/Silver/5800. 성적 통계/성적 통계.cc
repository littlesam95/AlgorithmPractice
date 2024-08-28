#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int K, N;
vector<int> Vec;

void input() {
    cin >> K;
    for (int i = 0; i < K; i++) {
        Vec.clear();
        cin >> N;
        Vec.resize(N);
        for (int j = 0; j < N; j++) {
            cin >> Vec[j];
        }
        int G = 0;
        sort(Vec.begin(), Vec.end());
        for (int j = 1; j < N; j++) {
            G = max(G, Vec[j] - Vec[j - 1]);
        }
        cout << "Class " << i + 1 << "\n";
        cout << "Max " << Vec[N - 1] << ", Min " << Vec[0] << ", Largest gap " << G << "\n";
    }
}

int main() {
    FASTIO
    input();

    return 0;
}