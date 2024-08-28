#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, M;

void input() {
    cin >> N;
    cin >> M;
    cout << (N - 1) * (M - 1) * 2 << "\n";
}

int main() {
    FASTIO
    input();

    return 0;
}