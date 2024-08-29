#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int T;
string A, B;
int Answer;

void init() {
    Answer = 0;
}

void input() {
    cin >> T;
    while (T--) {
        init();
        cin >> A;
        cin >> B;
        for (int i = 0; i < (int)A.size(); i++) {
            if (A[i] != B[i]) {
                Answer++;
            }
        }
        cout << "Hamming distance is " << Answer << ".\n";
    };
}

int main() {
    FASTIO
    input();

    return 0;
}