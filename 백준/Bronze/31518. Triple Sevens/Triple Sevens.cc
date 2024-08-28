#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, A;
bool Answer = true;

void input() {
    cin >> N;
    for (int i = 0; i < 3; i++) {
        bool Flag = false;
        for (int j = 0; j < N; j++) {
            cin >> A;
            if (A == 7) {
                Flag = true;
            }
        }
        Answer &= Flag;
    }
    if (Answer) {
        cout << "777\n";
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