#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
vector<int> Vec(3);

void input() {
    cin >> Vec[0] >> Vec[1] >> Vec[2];
    sort(Vec.begin(), Vec.end());
    cout << Vec[1] << "\n";
}

int main() {
    FASTIO
    input();

    return 0;
}