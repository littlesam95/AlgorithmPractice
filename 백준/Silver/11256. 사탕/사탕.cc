#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int T, J, N, R, C;
vector<int> Box;
int Answer;

void init() {
    Box.clear();
    Answer = 0;
}

bool comp(int A, int B) {
    return (A > B);
}

void settings() {
    sort(Box.begin(), Box.end(), comp);
    for (int i = 0; i < N; i++) {
        J -= Box[i];
        Answer++;
        if (J <= 0) {
            break;
        }
    }
}

void find_Answer() {
    cout << Answer << "\n";
}

void input() {
    cin >> T;
    while (T--) {
        init();
        cin >> J >> N;
        for (int i = 0; i < N; i++) {
            cin >> R >> C;
            Box.push_back(R * C);
        }
        settings();
        find_Answer();
    };
}

int main() {
    FASTIO
    input();

    return 0;
}