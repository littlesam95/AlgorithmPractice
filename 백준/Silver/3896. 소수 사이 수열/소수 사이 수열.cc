#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#define MAX 1299710
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int T, N;
int DP[MAX];
vector<int> Vec;
int Answer;

void init() {
    for (int i = 2; i < MAX; i++) {
        DP[i] = i;
    }
    for (int i = 2; i <= sqrt(MAX); i++) {
        if (DP[i] == 0) {
            continue;
        }
        for (int j = (i * i); j < MAX; j += i) {
            DP[j] = 0;
        }
    }
    for (int i = 2; i < MAX; i++) {
        if (DP[i] == i) {
            Vec.push_back(i);
        }
    }
}

void settings() {
    if (DP[N] == N) {
        Answer = 0;
    }
    else {
        int A = upper_bound(Vec.begin(), Vec.end(), N) - Vec.begin();
        Answer = Vec[A] - Vec[A - 1];
    }
}

void find_Answer() {
    cout << Answer << "\n";
}

void input() {
    cin >> T;
    while (T--) {
        cin >> N;
        settings();
        find_Answer();
    };
}

int main() {
    FASTIO
    init();
    input();

    return 0;
}