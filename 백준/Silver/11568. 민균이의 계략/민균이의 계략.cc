#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MAX 1001
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N;
int MAP[MAX];
vector<int> Answer;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> MAP[i];
    }
}

void settings() {
    for (int i = 0; i < N; i++) {
        if (Answer.empty()) {
            Answer.push_back(MAP[i]);
        }
        else {
            if (Answer.back() > MAP[i]) {
                int index = lower_bound(Answer.begin(), Answer.end(), MAP[i]) - Answer.begin();
                Answer[index] = MAP[i];
            }
            else if (Answer.back() < MAP[i]) {
                Answer.push_back(MAP[i]);
            }
        }
    }
}

void find_Answer() {
    cout << (int)Answer.size() << "\n";
}

int main() {
    FASTIO
    input();
    settings();
    find_Answer();

    return 0;
}