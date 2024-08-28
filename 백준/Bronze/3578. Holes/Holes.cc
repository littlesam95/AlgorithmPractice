#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int H;

void input() {
    cin >> H;
    if (H == 0) {
        cout << "1\n";
        return;
    }
    else if (H == 1) {
        cout << "0\n";
        return;
    }
    
    if (H % 2 == 1) {
        cout << "4";
    }
    for (int i = 0; i < (H / 2); i++) {
        cout << "8";
    }
}

int main() {
    FASTIO
    input();

    return 0;
}