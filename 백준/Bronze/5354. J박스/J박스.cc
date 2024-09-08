#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int T, N;

void find_Answer() {
    if (N == 1) {
        cout << "#\n";
        return;
    }
    for (int i = 0; i < N; i++) {
        cout << "#";
    }
    cout << "\n";
    for (int i = 0; i < (N - 2); i++) {
        cout << "#";
        for (int j = 0; j < (N - 2); j++) {
            cout << "J";
        }
        cout << "#\n";
    }
    for (int i = 0; i < N; i++) {
        cout << "#";
    }
    cout << "\n";
}

void input() {
    cin >> T;
    while (T--) {
        cin >> N;
        find_Answer();
        cout << "\n";              
    };
}

int main() {
    FASTIO
    input();

    return 0;
}