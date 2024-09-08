#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0);

using namespace std;
int D, H, M;
int Answer = 0;

void input() {
    cin >> D >> H >> M;
    int Day = D - 11;
    int Minute = (H - 11) * 60 + (M - 11);
    Answer = Day * 1440 + Minute;
    if (Answer < 0) {
        cout << "-1\n";
    }
    else {
        cout << Answer << "\n";
    }
}

int main() {
    FASTIO
    input();

    return 0;
}