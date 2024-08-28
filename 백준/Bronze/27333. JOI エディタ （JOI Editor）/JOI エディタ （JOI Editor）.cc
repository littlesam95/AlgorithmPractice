#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N;
string S;

void input() {
    cin >> N;
    cin >> S;
    for (int i = 1; i < N; i++) {
        if (S[i] == S[i - 1]) {
            S[i - 1] = toupper(S[i - 1]);
            S[i] = toupper(S[i]);
        }
    }
    cout << S << "\n";
}

int main() {
    FASTIO
    input();

    return 0;
}