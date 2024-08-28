#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
string S;

void input() {
    cin >> S;
    string tmpS = S;
    reverse(tmpS.begin(), tmpS.end());
    if (S == tmpS) {
        cout << "1\n";
    }
    else {
        cout << "0\n";
    }
}

int main() {
    FASTIO
    input();

    return 0;
}