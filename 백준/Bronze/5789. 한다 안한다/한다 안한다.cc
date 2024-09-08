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
    while (N--) {
        cin >> S;
        if (S[((int)S.size() / 2) - 1] == S[(int)S.size() / 2]) {
            cout << "Do-it\n";
        }
        else {
            cout << "Do-it-Not\n";
        }
    };
}

int main() {
    FASTIO
    input();

    return 0;
}