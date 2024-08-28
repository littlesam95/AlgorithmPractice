#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#define MAX 1001
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, R;
string P, S;
vector<string> Vec[MAX];
unordered_map<string, int> UM;
vector<pair<string, string> > Answer;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> P >> S;
        if (S != "-") {
            if (UM.find(S) == UM.end()) {
                UM.insert(make_pair(S, R++));
            }
            Vec[UM[S]].push_back(P);
        }
    }
    for (int i = 0; i < MAX; i++) {
        if ((int)Vec[i].size() == 2) {
            Answer.push_back(make_pair(Vec[i][0], Vec[i][1]));
        }
    }
    cout << (int)Answer.size() << "\n";
    for (int i = 0; i < (int)Answer.size(); i++) {
        cout << Answer[i].first << " " << Answer[i].second << "\n";
    }
}

int main() {
    FASTIO
    input();

    return 0;
}