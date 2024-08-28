#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
char C;
int W;
int Answer;

void input() {
    for (int i = 0; i < 8; i++) {
        if (i % 2 == 0) {
            W = 1;
        }
        else {
            W = 0;
        }
        for (int j = 0; j < 8; j++) {
            if (W == 1) {
                W = 0;
            }
            else {
                W = 1;
            }
            cin >> C;
            if ((W == 0) && (C == 'F')) {
                Answer++;
            }
        }
    }
}

void find_Answer() {
    cout << Answer << "\n";
}

int main() {
    FASTIO
    input();
    find_Answer();

    return 0;
}