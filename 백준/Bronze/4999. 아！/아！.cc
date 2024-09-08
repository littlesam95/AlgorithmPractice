#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
string A, B;

void input() {
    cin >> A;
    cin >> B;
    if (A.size() >= B.size()) {
        cout << "go\n";
    }
    else {
        cout << "no\n";
    }
}

int main() {
    FASTIO
    input();

    return 0;
}