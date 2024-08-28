#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
string A, B;
string Answer;

void input() {
    cin >> A;
    cin >> B;
    for (int i = 0; i < (int)A.length(); i++) {
        Answer += (A[i] > B[i]) ? A[i] : B[i];
    }
    cout << Answer << "\n";
}

int main() {
    FASTIO
    input();

    return 0;
}