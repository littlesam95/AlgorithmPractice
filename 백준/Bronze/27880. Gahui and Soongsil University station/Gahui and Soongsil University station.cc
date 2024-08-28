#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
string S;
int X;
int Answer;

void input() {
    while (cin >> S >> X) {
        if (S == "Es") {
            Answer += (21 * X);
        }
        else {
            Answer += (17 * X);
        }
    };
    cout << Answer << "\n";
}

int main() {
    FASTIO
    input();

    return 0;
}