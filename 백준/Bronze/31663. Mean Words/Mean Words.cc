#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#define MAX 46
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N;
string S;
int MAP[MAX], Count[MAX];

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> S;
        for (int j = 0; j < (int)S.size(); j++) {
            MAP[j] += (int)(S[j]);
            Count[j]++;
        }
    }
    for (int i = 0; i < MAX; i++) {
        if (MAP[i] == 0) {
            break;
        }
        cout << (char)(round(MAP[i] / Count[i]));
    }
    cout << "\n";
}

int main() {
    FASTIO
    input();

    return 0;
}