#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
double N;
double Answer;

void input() {
    while (1) {
        cin >> N;
        if (N == 0) {
            break;
        }
        Answer = 1 + N + (N * N) + (N * N * N) + (N * N * N * N);
        cout << fixed;
        cout.precision(2);
        cout << Answer << "\n";
    };
}

int main() {
    FASTIO
    input();

    return 0;
}