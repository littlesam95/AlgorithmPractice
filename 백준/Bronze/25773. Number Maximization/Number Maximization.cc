#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
string S;

bool comp(char A, char B) {
    return (A > B);
}

void input() {
    cin >> S;
    sort(S.begin(), S.end(), comp);
    cout << S << "\n";
}

int main() {
    FASTIO
    input();

    return 0;
}