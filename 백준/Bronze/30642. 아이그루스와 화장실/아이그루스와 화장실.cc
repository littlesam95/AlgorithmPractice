#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, K;
string S;

void input() {
    cin >> N;
    cin >> S;
    cin >> K;
    if (S == "annyong") {
        if (K % 2 == 0) {
            K++;
        }
    }
    else {
        if (K % 2 == 1) {
            K++;
        }
    }
    if (K > N) {
        K -= 2;
    }
    cout << K << "\n";
}

int main() {
    FASTIO
    input();

    return 0;
}