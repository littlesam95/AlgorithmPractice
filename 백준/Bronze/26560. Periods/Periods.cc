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
    cin.ignore();
    for (int i = 0; i < N; i++) {
        getline(cin, Vec[i]);
        if (Vec[i][(int)Vec[i].length() - 1] != '.') {
            Vec[i].push_back('.');
        }
    }
    for (int i = 0; i < N; i++) {
        cout << Vec[i] << "\n";
    }
}

int main() {
    FASTIO
    input();

    return 0;
}