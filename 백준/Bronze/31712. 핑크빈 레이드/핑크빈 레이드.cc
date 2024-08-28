#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int CU, DU, CD, DD, CP, DP, H;
int Answer;

void input() {
    cin >> CU >> DU;
    cin >> CD >> DD;
    cin >> CP >> DP;
    cin >> H;
    H -= (DU + DD + DP);

    while (H > 0) {
        Answer++;
        if (Answer % CU == 0) {
            H -= DU;
        }
        if (Answer % CD == 0) {
            H -= DD;
        }
        if (Answer % CP == 0) {
            H -= DP;
        }
    };

    cout << Answer << "\n";
}

int main() {
    FASTIO
    input();

    return 0;
}