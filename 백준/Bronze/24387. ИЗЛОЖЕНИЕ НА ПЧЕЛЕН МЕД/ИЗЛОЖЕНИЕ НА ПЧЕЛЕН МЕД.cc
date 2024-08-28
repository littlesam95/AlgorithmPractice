#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define LL long long
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
vector<LL> A(3), B(3);
LL Answer;

void input() {
    for (int i = 0; i < 3; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < 3; i++) {
        cin >> B[i];
    }
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());
    for (int i = 0; i < 3; i++) {
        Answer += (A[i] * B[i]);
    }
    cout << Answer << "\n";
}

int main() {
    FASTIO
    input();

    return 0;
}