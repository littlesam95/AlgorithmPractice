#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, X;
int Answer;

void input() {
    cin >> N;
    while (N--) {
        cin >> X;
        if (X == -1) {
            Answer--;
        }
        else if (X == 1) {
            Answer++;
        }
    };
    if (Answer > 0) {
        cout << "Right\n";
    }
    else if (Answer < 0) {
        cout << "Left\n";
    }
    else {
        cout << "Stay\n";
    }
}

int main() {
    FASTIO
    input();

    return 0;
}