#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#define MAX 11
#define INF 1e9
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N;
int M[MAX];
int Sub = INF;
int Answer;

void input() {
    for (int i = 1; i <= 10; i++) {
        cin >> N;
        M[i] = M[i - 1] + N;
    }
}

void find_Answer() {
    for (int i = 1; i <= 10; i++) {
        int Now = abs(100 - M[i]);
        if (Sub > Now) {
            Sub = Now;
            Answer = M[i];
        }
        else if (Sub == Now) {
            if (Answer < M[i]) {
                Answer = M[i];
            }
        }
    }
    cout << Answer << "\n";
}

int main() {
    FASTIO
    input();
    find_Answer();

    return 0;
}