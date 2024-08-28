#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <cmath>
#include <algorithm>
#define MAX 5000001
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N;
int Prime[MAX];
deque<char> DQ;
bool isBack = false;
int B, S;

void input() {
    cin >> N;
}

void eratosthenes() {
    for (int i = 2; i <= N; i++) {
        Prime[i] = i;
    }
    for (int i = 2; i <= sqrt(N); i++) {
        if (Prime[i] == 0) {
            continue;
        }
        for (int j = (i * i); j <= N; j += i) {
            Prime[j] = 0;
        }
    }
}

void settings() {
    eratosthenes();
    for (int i = 1; i <= N; i++) {
        if (Prime[i] == 0) {
            if (isBack) {
                DQ.push_back('B');
            }
            else {
                DQ.push_front('B');
            }
        }
        else {
            if (isBack) {
                char Last = DQ.back();
                if (Last == 'B') {
                    DQ.pop_back();
                    DQ.push_back('S');
                }
                DQ.push_back('S');
            }
            else {
                char Last = DQ.front();
                if (Last == 'B') {
                    DQ.pop_front();
                    DQ.push_front('S');
                }
                DQ.push_front('S');
            }
            isBack = !isBack;
        }
    }
    while (!DQ.empty()) {
        char Now = DQ.front();
        if (Now == 'B') {
            B++;
        }
        else {
            S++;
        }
        DQ.pop_front();
    };
}

void find_Answer() {
    cout << B << " " << S << "\n";
}

int main() {
    FASTIO
    input();
    settings();
    find_Answer();

    return 0;
}