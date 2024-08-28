#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, S;

void input() {
    while (cin >> N >> S) {
        cout << S / (N + 1) << "\n";
    };
}

int main() {
    FASTIO
    input();

    return 0;
}