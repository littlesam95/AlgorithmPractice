#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, K;

void input() {
    cin >> N >> K;
    for (int i = 1; i < N; i++) {
        K /= 2;
    }
    cout << K << "\n";
}

int main() {
    FASTIO
    input();

    return 0;
}