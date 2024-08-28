#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MAX 10
#define FASTIO cin.tie(0); cout.tie(0);

using namespace std;
int K;
vector<char> Vec;
bool visited[MAX];
vector<string> Answer;

void input() {
    cin >> K;
    for (int i = 0; i < K; i++) {
        char C;
        cin >> C;
        Vec.push_back(C);
    }
}

void DFS(int Depth, string S, int End) {
    if (S.size() == K + 1) {
        Answer.push_back(S);
        return;
    }

    if (Vec[Depth] == '<') {
        for (int i = End + 1; i <= 9; i++) {
            if (!visited[i]) {
                visited[i] = true;
                DFS(Depth + 1, S + to_string(i), i);
                visited[i] = false;
            }
        }
    }
    else {
        for (int i = 0; i < End; i++) {
            if (!visited[i]) {
                visited[i] = true;
                DFS(Depth + 1, S + to_string(i), i);
                visited[i] = false;
            }
        }
    }
}

void settings() {
    for (int i = 0; i <= 9; i++) {
        visited[i] = true;
        DFS(0, to_string(i), i);
        visited[i] = false;
    }
}

void find_Answer() {
    sort(Answer.begin(), Answer.end());
    cout << Answer[Answer.size() - 1] << "\n";
    cout << Answer[0] << "\n";
}

int main() {
    FASTIO
    input();
    settings();
    find_Answer();

    return 0;
}