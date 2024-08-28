#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
vector<int> Vec;
int AnswerW, AnswerK;

void input() {
    Vec.resize(10);
    for (int i = 0; i < 10; i++) {
        cin >> Vec[i];
    }
    sort(Vec.begin(), Vec.end());
    AnswerW = Vec[7] + Vec[8] + Vec[9];
    Vec.clear();
    Vec.resize(10);
    for (int i = 0; i < 10; i++) {
        cin >> Vec[i];
    }
    sort(Vec.begin(), Vec.end());
    AnswerK = Vec[7] + Vec[8] + Vec[9];
    cout << AnswerW << " " << AnswerK << "\n";
}

int main() {
    FASTIO
    input();

    return 0;
}