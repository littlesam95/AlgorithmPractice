#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N;
string K;
int odd, even;

void input() {
    cin >> N;
    cin >> K;
    for (int i = 0; i < N; i++) {
        int Now = K[i] - '0';
        if (Now % 2 == 0) {
            even++;
        }
        else {
            odd++;
        }
    }

    if (odd > even) {
        cout << "1\n";
    }
    else if (odd < even) {
        cout << "0\n";
    }
    else {
        cout << "-1\n";
    }
}

int main() {
    FASTIO
    input();

    return 0;
}