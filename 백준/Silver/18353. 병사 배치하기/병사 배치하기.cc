#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MAX 2001
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, X;
vector<int> Vec;
int DP[MAX];
vector<int> Answer;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> X;
        Vec.push_back(X);
    }
    reverse(Vec.begin(), Vec.end());
}

void settings() {
    for (int i = 0; i < N; i++) {
        if (Answer.empty()) {
            Answer.push_back(Vec[i]);
        }
        else {
            if (Answer.back() < Vec[i]) {
                Answer.push_back(Vec[i]);
            }
            else {
                int index = lower_bound(Answer.begin(), Answer.end(), Vec[i]) - Answer.begin();
                Answer[index] = Vec[i];
            }
        }
    }
}

void find_Answer() {
    cout << N - (int)Answer.size() << "\n";
}

int main() {
    FASTIO
    input();
    settings();
    find_Answer();

    return 0;
}