#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int T, N;

void find_Answer() {
    cout << "Pairs for " << N << ":";
    int Count = 0;
    for (int i = 1; i <= 12; i++) {
        int Prev = i;
        int Next = N - i;
        if ((Next >= 1) && (Prev < Next)) {
            if (Count == 0) {
                cout << " " << Prev << " " << Next;
                Count++;
            }
            else {
                cout << ", " << Prev << " " << Next;
            }
        }
    }
    cout << "\n";
}

void input() {
    cin >> T;
    while (T--) {
        cin >> N;
        find_Answer();                
    };
}

int main() {
    FASTIO
    input();

    return 0;
}