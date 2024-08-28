#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
string S;
deque<char> DQ;

void input() {
    cin >> S;
}

void settings() {
    for (int i = 0; i < S.size(); i++) {
        char Now = S[i];
        if (DQ.empty()) {
            DQ.push_back(Now);
        }
        else if (DQ.back() <= Now) {
            DQ.push_back(Now);
        }
        else if (DQ.front() >= Now) {
            DQ.push_front(Now);
        }
        else {
            DQ.push_back(Now);
        }
    }
}

void find_Answer() {
    while (!DQ.empty()) {
        cout << DQ.front();
        DQ.pop_front();
    };
    cout << "\n";
}

int main() {
    FASTIO
    input();
    settings();
    find_Answer();

    return 0;
}