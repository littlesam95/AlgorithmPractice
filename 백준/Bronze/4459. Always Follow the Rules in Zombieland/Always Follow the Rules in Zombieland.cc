#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int Q, R, Rule;
vector<string> Vec;

void input() {
    cin >> Q;
    cin.ignore();
    Vec.resize(Q);
    for (int i = 0; i < Q; i++) {
        getline(cin, Vec[i]);
    }
    cin >> R;
    for (int i = 0; i < R; i++) {
        cin >> Rule;
        if ((Rule > 0) && (Rule <= Q)) {
            cout << "Rule " << Rule << ": " << Vec[Rule - 1] << "\n";
        }
        else {
            cout << "Rule " << Rule << ": No such rule\n";
        }
    }
}

int main() {
    FASTIO
    input();

    return 0;
}