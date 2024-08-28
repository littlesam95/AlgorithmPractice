#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
string S;

void input() {
    while (getline(cin, S)) {
        cout << S << "\n";
    };
}

int main() {
    FASTIO
    input();

    return 0;
}