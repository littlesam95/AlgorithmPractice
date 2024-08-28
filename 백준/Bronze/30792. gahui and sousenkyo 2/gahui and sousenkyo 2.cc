#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, M, K;
int Answer = 1;

void input() {
    cin >> N;
    N--;
    cin >> M;
    while (N--) {
        cin >> K;
        if (K > M) {
            Answer++;
        }
    };
    cout << Answer << "\n";
}

int main() {
    FASTIO
    input();

    return 0;
}