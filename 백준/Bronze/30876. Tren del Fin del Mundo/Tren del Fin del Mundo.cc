#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, X, Y;
pair<int, int> Answer = make_pair(1001, 1001);

void input() {
    cin >> N;
    while (N--) {
        cin >> X >> Y;
        if (Answer.second > Y) {
            Answer = make_pair(X, Y);
        }
    };
    cout << Answer.first << " " << Answer.second << "\n";
}

int main() {
    FASTIO
    input();

    return 0;
}