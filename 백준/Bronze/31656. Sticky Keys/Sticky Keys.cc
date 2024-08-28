#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
string S;

void input() {
    getline(cin, S);
    S.erase(unique(S.begin(), S.end()), S.end());
    cout << S << "\n";
}

int main() {
    FASTIO
    input();

    return 0;
}