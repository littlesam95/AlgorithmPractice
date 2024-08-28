#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
string A, B, C;

void input() {
    cin >> A;
    cin >> B;
    cin >> C;
    cout << stoi(A) + stoi(B) - stoi(C) << "\n";
    cout << stoi(A + B) - stoi(C) << "\n";
}

int main() {
    FASTIO
    input();

    return 0;
}