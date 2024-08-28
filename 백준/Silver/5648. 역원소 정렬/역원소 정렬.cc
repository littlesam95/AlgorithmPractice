#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define LL long long
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N;
string S;
vector<LL> Vec;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> S;
        reverse(S.begin(), S.end());
        Vec.push_back(stoll(S));
    }
    sort(Vec.begin(), Vec.end());
    for (int i = 0; i < N; i++) {
        cout << Vec[i] << "\n";
    }
}

int main() {
    FASTIO
    input();

    return 0;
}