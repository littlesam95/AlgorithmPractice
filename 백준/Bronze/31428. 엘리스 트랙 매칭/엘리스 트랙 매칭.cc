#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N;
vector<char> Vec;
char Me;
int Answer;

void input() {
    cin >> N;
    Vec.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> Vec[i];
    }
    cin >> Me;
}

void settings() {
    for (int i = 0; i < N; i++) {
        if (Me == Vec[i]) {
            Answer++;
        }
    }
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