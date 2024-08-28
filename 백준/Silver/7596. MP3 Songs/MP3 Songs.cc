#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, T;
vector<string> Vec;

void input() {
    while (1) {
        Vec.clear();
        cin >> N;
        if (N == 0) {
            break;
        }
        Vec.resize(N);
        cin.ignore();
        for (int i = 0; i < N; i++) {
            getline(cin, Vec[i]);
        }
        sort(Vec.begin(), Vec.end());
        cout << ++T << "\n";
        for (int i = 0; i < N; i++) {
            cout << Vec[i] << "\n";
        }
    };
}

int main() {
    FASTIO
    input();

    return 0;
}