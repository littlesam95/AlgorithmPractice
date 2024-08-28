#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, L;
vector<int> H;

void input() {
    cin >> N >> L;
    H.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }
}

void settings() {
    sort(H.begin(), H.end());
    for (int i = 0; i < (int)H.size(); i++) {
        int Now = H[i];
        if (Now <= L) {
            L++;
        }
    }
}

void find_Answer() {
    cout << L << "\n";
}

int main() {
    FASTIO
    input();
    settings();
    find_Answer();

    return 0;
}