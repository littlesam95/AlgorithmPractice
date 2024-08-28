#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, K, Cnt;
vector<int> Vec;
vector<int> Answer;

void input() {
    cin >> N >> K;
    Vec.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> Vec[i];
    }
    for (int i = (N - 1); i >= 1; i--) {
        int Most = 0;
        for (int j = 1; j <= i; j++) {
            if (Vec[Most] < Vec[j]) {
                Most = j;
            }
        }
        if (Most != i) {
            swap(Vec[Most], Vec[i]);
            Cnt++;
        }
        if (Cnt == K) {
            Answer.push_back(Vec[Most]);
            Answer.push_back(Vec[i]);
            break;   
        }
    }

    if (Answer.empty()) {
        cout << "-1\n";
    }
    else {
        sort(Answer.begin(), Answer.end());
        cout << Answer[0] << " " << Answer[1] << "\n";
    }
}

int main() {
    FASTIO
    input();

    return 0;
}