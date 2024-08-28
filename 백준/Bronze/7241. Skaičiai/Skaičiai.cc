#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
vector<int> Vec(3);
vector<int> Tmp(3);
string S;
int Answer;

void input() {
    cin >> Vec[0] >> Vec[1] >> Vec[2];
    cin >> S;
    for (int i = 0; i < 3; i++) {
        Tmp[i] = S[i] - '0';
    }

    sort(Vec.begin(), Vec.end());

    do {
        Answer++;
        if ((Vec[0] == Tmp[0]) && (Vec[1] == Tmp[1]) && (Vec[2] == Tmp[2])) {
            cout << Answer << "\n";
            return;
        }
    } while (next_permutation(Vec.begin(), Vec.end()));
}

int main() {
    FASTIO
    input();

    return 0;
}