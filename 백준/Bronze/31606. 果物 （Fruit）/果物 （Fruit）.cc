#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int X, Y;

void input() {
    cin >> X;
    cin >> Y;
    cout << (X + Y + 3) << "\n";
}

int main() {
    FASTIO
    input();

    return 0;
}