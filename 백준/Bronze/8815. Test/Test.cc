#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int Z, N;
char Words[4] = { 'A','B','C','D' };

void input() {
    cin >> Z;
    while (Z--) {
        cin >> N;
        int Moved = (N - 1) / 3;
        int Remain = (N - 1) % 3;
        cout << Words[(Moved + Remain) % 4] << "\n";
    };
}

int main() {
    FASTIO
    input();

    return 0;
}