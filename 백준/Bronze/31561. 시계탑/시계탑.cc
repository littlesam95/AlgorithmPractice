#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
double M;

void input() {
    cin >> M;
    cout << fixed;
    cout.precision(1);
    if (M <= 30) {
        cout << (M / 2) << "\n";
    }
    else {
        cout << 15 + ((M - 30) * 1.5) << "\n";
    }
}

int main() {
    FASTIO
    input();

    return 0;
}