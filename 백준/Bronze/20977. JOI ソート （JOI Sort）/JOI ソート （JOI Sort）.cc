#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N;
string S, A;

void input() {
    cin >> N;
    cin >> S;
    for (int i = 0; i < N; i++) {
        char Now = S[i];
        if (Now == 'J') {
            A += "0";
        }
        else if (Now == 'O') {
            A += "1";
        }
        else if (Now == 'I') {
            A += "2";
        }
    }
    sort(A.begin(), A.end());
    for (int i = 0; i < N; i++) {
        char Now = A[i];
        if (Now == '0') {
            cout << "J";
        }
        else if (Now == '1') {
            cout << "O";
        }
        else if (Now == '2') {
            cout << "I";
        }
    }
    cout << "\n";
}

int main() {
    FASTIO
    input();

    return 0;
}