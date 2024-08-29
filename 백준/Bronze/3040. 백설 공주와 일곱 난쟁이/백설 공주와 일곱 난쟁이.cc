#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
vector<int> Vec;
vector<int> Answer;

void input() {
    Vec.resize(9);
    for (int i = 0; i < 9; i++) {
        cin >> Vec[i];
    }
}

void settings() {
    sort(Vec.begin(), Vec.end());
    do {
        int Value = 0;
        for (int i = 0; i < 7; i++) {
            Value += Vec[i];
        }
        if (Value == 100) {
            for (int i = 0; i < 7; i++) {
                Answer.push_back(Vec[i]);
            }
            break;
        }
    } while (next_permutation(Vec.begin(), Vec.end()));
    sort(Answer.begin(), Answer.end());
}

void find_Answer() {
    for (int i = 0; i < 7; i++) {
        cout << Answer[i] << "\n";
    }
}

int main() {
    FASTIO
    input();
    settings();
    find_Answer();

    return 0;
}