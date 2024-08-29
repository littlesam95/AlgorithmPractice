#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N;
int Answer;

void input() {
    cin >> N;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (N - i - j == 0) {
                Answer++;
            }
        }
    }
    cout << Answer << "\n";
}

int main() {
    FASTIO
    input();

    return 0;
}