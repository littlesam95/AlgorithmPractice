#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#define MAX 10001

using namespace std;
int N, M;
int DP[MAX];
int answer1 = 0;
int answer2 = MAX;

void Eratosthenes() {
    for (int i = 2; i < MAX; i++) {
        DP[i] = i;
    }
    for (int i = 2; i <= sqrt(MAX); i++) {
        DP[i * i] = 0;
    }
    for (int i = 2; i < MAX; i++) {
        if (DP[i] == 0) {
            continue;
        }
        for (int j = i * i; j < MAX; j += i) {
            DP[j] = 0;
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    
    Eratosthenes();
    cin >> M;
    cin >> N;
    for (int i = M; i <= N; i++) {
        if (DP[i] != 0) {
            answer1 += i;
            answer2 = min(answer2, i);
        }
    }
    if (answer1 > 0) {
        cout << answer1 << "\n";
        cout << answer2 << "\n";
    }
    else if (answer1 == 0) {
        cout << -1 << "\n";
    }
    
    return 0;
}