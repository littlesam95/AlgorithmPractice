#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int A, B;

void input() {
    cin >> A;
    cin >> B;
    cout << (int)to_string(A + B).length() << "\n";
}

int main() {
    FASTIO
    input();

    return 0;
}