#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N;
string A, B;
int Answer;

void input() {
    cin >> N;
    cin >> A;
    cin >> B;
    for (int i = 0; i < N; i++) {
        if (A[i] != B[i]) Answer++;
    }
    cout << Answer << "\n";
}

int main() {
    FASTIO
    input();

    return 0;
}