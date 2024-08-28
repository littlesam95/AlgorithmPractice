#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, K;
deque<int> DQ;

void input() {
    cin >> N >> K;
}

void settings() {
    for (int i = 1; i <= N; i++) {
        DQ.push_back(i);
    }
    while (DQ.size() > 1) {
        if (DQ.size() >= K) {
            int Front = DQ.front();
            for (int i = 0; i < K; i++) {
                DQ.pop_front();
            }
            DQ.push_front(Front);
        }
        else {
            while (DQ.size() > 1) {
                DQ.pop_back();
            };
        }

        int Front = DQ.front();
        DQ.pop_front();
        DQ.push_back(Front);
    };
}

void find_Answer() {
    cout << DQ.front() << "\n";
}

int main() {
    FASTIO
    input();
    settings();
    find_Answer();

    return 0;
}