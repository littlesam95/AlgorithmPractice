#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int T, Case;
string S;
unordered_map<int, char> UM;
vector<int> Vec;

void input() {
    cin >> T;
    while (T--) {
        cin >> S;
        Vec.clear();
        for (int i = 0; i < (int)S.size(); i++) {
            UM[i] = S[i];
            Vec.push_back(i);
        }
        cout << "Case # " << ++Case << ":\n";
        do {
            for (int i = 0; i < (int)Vec.size(); i++) {
                cout << UM[Vec[i]];
            }
            cout << "\n";
        } while (next_permutation(Vec.begin(), Vec.end()));
    };
}

int main() {
    FASTIO
    input();

    return 0;
}