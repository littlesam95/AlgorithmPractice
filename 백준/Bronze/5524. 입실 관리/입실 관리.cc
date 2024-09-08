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
    while (N--) {
        cin >> S;
        for (int i = 0; i < S.size(); i++) {
            S[i] = tolower(S[i]);
        }
        cout << S << "\n";
    };
}

int main() {
    FASTIO
    input();

    return 0;
}