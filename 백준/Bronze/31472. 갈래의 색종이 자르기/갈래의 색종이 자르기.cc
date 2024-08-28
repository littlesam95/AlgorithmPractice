#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int W;

void input() {
    cin >> W;
    for (int i = 1; i <= W; i++) {
        if ((W / i) * 2 == i) {
            cout << (i * 4) << "\n";
            return;
        }
    }
}

int main() {
    FASTIO
    input();

    return 0;
}