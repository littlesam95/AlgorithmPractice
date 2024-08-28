#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MAX 5
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
string S[MAX];
int max_len;
string Answer = "";

void input() {
    for (int i = 0; i < MAX; i++) {
        cin >> S[i];
        max_len = max(max_len, (int)S[i].length());
    }
}

void settings() {
    for (int i = 0; i < max_len; i++) {
        for (int j = 0; j < MAX; j++) {
            if ((int)S[j].length() <= i) continue;
            Answer += S[j][i];
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