#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N;
vector<string> Vec;
vector<string> Answer;

void input() {
    cin >> N;
    Vec.resize(N + 1);
    for (int i = 0; i < N; i++) {
        cin >> Vec[i];
    }
    Vec[N] = "";

    for (int i = 0; i < N; i++) {   
        if ((Vec[i] != "Present!") && (Vec[i + 1] != "Present!")) {
            Answer.push_back(Vec[i]);
        }
    }

    if (Answer.empty()) {
        cout << "No Absences\n";
    }
    else {
        for (int i = 0; i < (int)Answer.size(); i++) {
            cout << Answer[i] << "\n";
        }
    }
}

int main() {
    FASTIO
    input();

    return 0;
}