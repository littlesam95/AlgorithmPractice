#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MAX 101
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N;
int MAP[MAX];

void init() {
    for (int i = 1; i < MAX; i++) {
        MAP[i] = MAP[i - 1] + i;
    }
}

void input() {
    while (1) {
        cin >> N;
        if (N == 0) {
            return;
        }
        cout << MAP[N] << "\n";
    };
}

int main() {
    FASTIO
    init();
    input();

    return 0;
}