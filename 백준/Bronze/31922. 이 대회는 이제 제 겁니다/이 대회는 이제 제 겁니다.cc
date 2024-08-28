#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int A, P, C;

void input() {
    cin >> A >> P >> C;
    cout << max(A + C, P) << "\n";
}

int main() {
    FASTIO
    input();

    return 0;
}