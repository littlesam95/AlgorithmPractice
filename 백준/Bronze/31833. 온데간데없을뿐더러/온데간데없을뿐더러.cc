#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N;
string S, X, Y;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> S;
        X += S;
    }
    for (int i = 0; i < N; i++) {
        cin >> S;
        Y += S;
    }
    if (stoll(X) > stoll(Y)) {
        cout << Y << "\n";
    }
    else {
        cout << X << "\n";
    }
}

int main() {
    FASTIO
    input();

    return 0;
}