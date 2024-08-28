#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, K;
int Index;
int Answer;

void input() {
    cin >> N >> K;
}

void settings() {
    for (int i = 1; i <= N; i++) {
        if (N % i == 0) {
            Index++;
            if (Index == K) {
                Answer = i;
                break;
            }
        }
    }
}

void find_Answer() {
    cout << Answer << "\n";
}

int main() {
    FASTIO
    input();
    settings();
    find_Answer();

    return 0;
}