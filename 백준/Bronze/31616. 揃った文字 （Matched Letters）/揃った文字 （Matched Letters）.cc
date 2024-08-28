#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N;
string S;
bool Answer = true;

void input() {
    cin >> N;
    cin >> S;
    for (int i = 1; i < N; i++) {
        if (S[i - 1] != S[i]) {
            Answer = false;
        }
    }

    if (Answer) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }
}

int main() {
    FASTIO
    input();

    return 0;
}