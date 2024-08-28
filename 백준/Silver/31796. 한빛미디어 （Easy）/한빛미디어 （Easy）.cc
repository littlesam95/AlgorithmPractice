#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N;
vector<int> S;
int Answer;

void input() {
    cin >> N;
    S.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
}

void settings() {
    sort(S.begin(), S.end());

    int Start = S[0];
    for (int i = 1; i < N; i++) {
        int Now = S[i];
        if (Start * 2 <= Now) {
            Answer++;
            Start = Now;
        }
    }
    Answer++;
}

void find_Answer() {
    cout << Answer << "\n";
}

int main() {
    FASTIO
    input();
    settings();
    find_Answer();

    return 0;
}