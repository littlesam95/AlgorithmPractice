#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#define MAX 4000001
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int DP[MAX];
int A, B, D;
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
}

void input() {
    cin >> A >> B >> D;
}

void settings() {
    for (int i = A; i <= B; i++) {
        if (DP[i] == i) {
            string S = to_string(i);
            bool Flag = false;
            for (int j = 0; j < S.size(); j++) {
                char Now = S[j];
                if ((Now - '0') == D) {
                    Flag = true;
                    break;
                }
            }
            if (Flag) {
                Answer++;
            }
        }
    }
}

void find_Answer() {
    cout << Answer << "\n";
}

int main() {
    FASTIO
    init();
    input();
    settings();
    find_Answer();

    return 0;
}