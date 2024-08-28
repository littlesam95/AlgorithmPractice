#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int H, M;

void input() {
    cin >> H;
    cin >> M;
    cout << (H * 60) + M << "\n";
}

int main() {
    FASTIO
    input();

    return 0;
}