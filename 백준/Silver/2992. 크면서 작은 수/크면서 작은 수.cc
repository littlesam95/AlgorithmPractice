#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MAX 6
#define INF 1e9
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int Number;
string S;
bool Visited[MAX];
int Answer = INF;

void input() {
    cin >> Number;
}

void DFS(int Depth, string Now) {
    if (Depth == S.size()) {
        if (Number < stoi(Now)) {
            Answer = min(Answer, stoi(Now));
        }
        return;
    }

    for (int i = 0; i < S.size(); i++) {
        if (!Visited[i]) {
            Visited[i] = true;
            DFS(Depth + 1, Now + S[i]);
            Visited[i] = false;
        }
    }
}

void settings() {
    S = to_string(Number);
    sort(S.begin(), S.end());
    DFS(0, "");
}

void find_Answer() {
    if (Answer == INF) {
        cout << "0\n";
    }
    else {
        cout << Answer << "\n";
    }
}

int main() {
    FASTIO
    input();
    settings();
    find_Answer();

    return 0;
}