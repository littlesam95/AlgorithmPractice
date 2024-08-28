#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int i = 0; i < N; i++) {
            cout << "G";
        }
        for (int i = 0; i < N; i++) {
            cout << ".";
        }
        for (int i = 0; i < N; i++) {
            cout << ".";
        }
        for (int i = 0; i < N; i++) {
            cout << ".";
        }
        cout << "\n";
    }
    for (int i = 0; i < N; i++) {
        for (int i = 0; i < N; i++) {
            cout << ".";
        }
        for (int i = 0; i < N; i++) {
            cout << "I";
        }
        for (int i = 0; i < N; i++) {
            cout << ".";
        }
        for (int i = 0; i < N; i++) {
            cout << "T";
        }
        cout << "\n";
    }
    for (int i = 0; i < N; i++) {
        for (int i = 0; i < N; i++) {
            cout << ".";
        }
        for (int i = 0; i < N; i++) {
            cout << ".";
        }
        for (int i = 0; i < N; i++) {
            cout << "S";
        }
        for (int i = 0; i < N; i++) {
            cout << ".";
        }
        cout << "\n";
    }
}

int main() {
    FASTIO
    input();

    return 0;
}