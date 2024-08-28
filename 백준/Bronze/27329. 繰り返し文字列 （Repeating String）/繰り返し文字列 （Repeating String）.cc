#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N;
string S;

void input() {
    cin >> N;
    cin >> S;
    if (S.substr(0, N / 2) == S.substr(N / 2)) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }
}

int main() {
    FASTIO
    input();

    return 0;
}