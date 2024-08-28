#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MAX 1001
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N;
vector<int> Vec;
int Answer;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        Vec.clear();
        Vec.resize(3);
        cin >> Vec[0] >> Vec[1] >> Vec[2];
        sort(Vec.begin(), Vec.end());
        if ((Vec[0] == Vec[1]) && (Vec[1] == Vec[2])) {
            Answer = max(Answer, 10000 + (Vec[0] * 1000));
        }
        else if ((Vec[0] == Vec[1])) {
            Answer = max(Answer, 1000 + (Vec[0] * 100));
        }
        else if ((Vec[1] == Vec[2])) {
            Answer = max(Answer, 1000 + (Vec[1] * 100));
        }
        else if ((Vec[2] == Vec[0])) {
            Answer = max(Answer, 1000 + (Vec[2] * 100));
        }
        else {
            Answer = max(Answer, Vec[2] * 100);
        }
    }
    cout << Answer << "\n";
}

int main() {
    FASTIO
    input();

    return 0;
}