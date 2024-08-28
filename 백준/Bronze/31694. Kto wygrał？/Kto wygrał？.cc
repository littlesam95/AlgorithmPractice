#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MAX 11
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int S, A, B;
int AS[MAX], BS[MAX];

void input() {
    for (int i = 0; i < 18; i++) {
        cin >> S;
        AS[S]++;
        A += S;
    }
    for (int i = 0; i < 18; i++) {
        cin >> S;
        BS[S]++;
        B += S;
    }
    if (A > B) {
        cout << "Algosia\n";
    }
    else if (A < B) {
        cout << "Bajtek\n";
    }
    else {
        for (int i = 10; i >= 0; i--) {
            if (AS[i] > BS[i]) {
                cout << "Algosia\n";
                return;
            }
            else if (AS[i] < BS[i]) {
                cout << "Bajtek\n";
                return;
            }
        }
        cout << "remis\n";
    }
}

int main() {
    FASTIO
    input();

    return 0;
}