#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N;
vector<string> Vec;

void input() {
    cin >> N;
    Vec.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> Vec[i];
    }
}

void settings() {
    sort(Vec.begin(), Vec.end());
}

void find_Answer() {
    for (int i = 0; i < N; i++) {
        string Now = Vec[i];
        if ((int)Now.length() != 3) {
            continue;
        }
        cout << Now << "\n";
        return;
    }
}

int main() {
    FASTIO
    input();
    settings();
    find_Answer();

    return 0;
}