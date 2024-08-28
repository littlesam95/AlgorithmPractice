#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define INF 2e9
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int A, B, C, D;
int Min = INF;
int Max = -1;

void input() {
    for (int i = 0; i < 3; i++) {
        cin >> A >> B >> C >> D;
        int Prev = (A * 60) + B;
        int Next = (C * 60) + D;
        int Sub = Next - Prev;
        if (Sub < 0) {
            Sub += (24 * 60);
        }
        Min = min(Min, Sub);
        Max = max(Max, Sub);
    }
    cout << (Min / 60) << ":";
    if ((Min % 60) < 10) {
        cout << "0";
    }
    cout  << (Min % 60) << "\n";
    cout << (Max / 60) << ":";
    if ((Max % 60) < 10) {
        cout << "0";
    }
    cout << (Max % 60) << "\n";
}

int main() {
    FASTIO
    input();

    return 0;
}