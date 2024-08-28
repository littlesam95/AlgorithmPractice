#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define INF 1e9
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, X, Y;
int MaxY = -1e9 - 1, MinY = 1e9 + 1;

void input() {
    cin >> N;
    while (N--) {
        cin >> X >> Y;
        MaxY = max(MaxY, Y);
        MinY = min(MinY, Y);
    };
    cout << MaxY - MinY << "\n";
}

int main() {
    FASTIO
    input();

    return 0;
}