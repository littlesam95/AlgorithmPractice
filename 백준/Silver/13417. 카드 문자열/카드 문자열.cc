#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int T, N;
char C;
deque<char> DQ;

void settings() {
    if (DQ.empty()) {
        DQ.push_front(C);
        return;
    }

    char Front = DQ.front();
    if (Front < C) {
        DQ.push_back(C);
    }
    else {
        DQ.push_front(C);
    }
}

void find_Answer() {
    while (!DQ.empty()) {
        cout << DQ.front();
        DQ.pop_front();
    };
    cout << "\n";
}

void input() {
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> C;
            settings();
        }
        find_Answer();
    };
}

int main() {
    FASTIO
    input();

    return 0;
}