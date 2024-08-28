#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int M, K;

void input() {
    cin >> M >> K;
    if (M % K == 0) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }
}

int main() {
    FASTIO
    input();

    return 0;
}