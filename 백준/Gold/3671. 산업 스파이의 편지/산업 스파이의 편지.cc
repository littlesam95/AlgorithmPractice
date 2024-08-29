#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <set>
#include <algorithm>
#define MAX 10000001
#define LL long long
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int DP[MAX];
bool Visited[7];
int C;
string N;
set<int> Answer;

void init() {
    for (int i = 2; i < MAX; i++) {
        DP[i] = i;
    }
    for (int i = 2; i <= sqrt(MAX); i++) {
        if (DP[i] == 0) {
            continue;
        }
        for (int j = (i * i); j < MAX; j += i) {
            DP[j] = 0;
        }
    }
}

void DFS(int Depth, string Now) {
    if (Depth > (int)N.size()) {
        return;
    }

    if (!Now.empty()) {
        int Result = stoi(Now);
        if (Result == 0) {
            return;
        }
        if (DP[Result] == Result) {
            Answer.insert(Result);
        }
    }

    for (int i = 0; i < (int)N.size(); i++) {
        if (!Visited[i]) {
            Visited[i] = true;
            DFS(Depth + 1, Now + N[i]);
            Visited[i] = false;
        }
    }
}

void settings() {
    Answer.clear();
    DFS(0, "");
}

void find_Answer() {
    cout << (int)Answer.size() << "\n";
}

void input() {
    cin >> C;
    while (C--) {
        cin >> N;
        settings();
        find_Answer();
    };
}

int main() {
    FASTIO
    init();
    input();

    return 0;
}