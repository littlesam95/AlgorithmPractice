#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, M, K;

void input() {
    cin >> N >> M >> K;
    cout << (M / N) * K << "\n";
}

int main() {
    FASTIO
    input();

    return 0;
}