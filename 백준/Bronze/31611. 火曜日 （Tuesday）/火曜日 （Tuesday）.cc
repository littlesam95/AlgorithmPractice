#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int X;

void input() {
    cin >> X;
    if ((X % 7) == 2) {
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