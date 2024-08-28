#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0);

using namespace std;
string N;
int A, W;

void input() {
    while (1) {
        cin >> N >> A >> W;
        if ((N == "#") && (A == 0) && (W == 0)) {
            break;
        }
        if ((A > 17) || (W >= 80)) {
            cout << N << " Senior\n";
        }
        else {
            cout << N << " Junior\n";
        }
    };
}

int main() {
    FASTIO
    input();

    return 0;
}