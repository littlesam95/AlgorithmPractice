#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, M;
string S;
int Answer;

void input() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> S;
        for (int j = 0; j < M; j++) {
            if (S[j] == '+') {
                Answer++;
                break;
            }
        }
    }
    cout << Answer << "\n";
}

int main() {
    FASTIO
    input();

    return 0;
}