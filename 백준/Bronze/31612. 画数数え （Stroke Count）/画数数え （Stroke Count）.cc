#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N;
string S;
int Answer;

void input() {
    cin >> N;
    cin >> S;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'o') {
            Answer++;
        }
        else {
            Answer += 2;
        }
    }
    cout << Answer << "\n";
}

int main() {
    FASTIO
    input();

    return 0;
}