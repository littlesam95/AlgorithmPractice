#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0);

using namespace std;
int A, B, C;
vector<int> Vec;
string S;

void input() {
    for (int i = 0; i < 3; i++) {
        int I;
        cin >> I;
        Vec.push_back(I);
    }
    sort(Vec.begin(), Vec.end());
    A = Vec[0];
    B = Vec[1];
    C = Vec[2];
    cin >> S;
    for (int i = 0; i < 3; i++) {
        if (S[i] == 'A') {
            cout << Vec[0] << " ";
        }
        else if (S[i] == 'B') {
            cout << Vec[1] << " ";
        }
        else {
            cout << Vec[2] << " ";
        }
    }
    cout << "\n";
}

int main() {
    FASTIO
    input();

    return 0;
}