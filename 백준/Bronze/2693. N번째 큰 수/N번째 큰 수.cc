#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int T;
vector<int> Vec(10);

void input() {
    cin >> T;
    while (T--) {
        for (int i = 0; i < 10; i++) {
            cin >> Vec[i];
        }
        sort(Vec.begin(), Vec.end());
        cout << Vec[7] << "\n";
    };
}

int main() {
    FASTIO
    input();

    return 0;
}