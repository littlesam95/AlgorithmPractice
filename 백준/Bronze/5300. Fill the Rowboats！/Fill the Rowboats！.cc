#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N;

void input() {
    cin >> N;
    for (int i = 1; i < N; i++) {
        cout << i << " ";
        if (i % 6 == 0) {
            cout << "Go! ";
        }
    }
    cout << N << " Go!\n";
}

int main() {
    FASTIO
    input();

    return 0;
}