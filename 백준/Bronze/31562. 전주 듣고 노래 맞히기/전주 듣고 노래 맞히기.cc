#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#define MAX 1001
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, M, T;
string S;
unordered_map<int, string> UM;
char Sound[MAX][7];
vector<char> Vec;

void find_Answer() {
    vector<string> Answer;
    for (int i = 0; i < N; i++) {
        if ((Vec[0] == Sound[i][0]) && (Vec[1] == Sound[i][1]) && (Vec[2] == Sound[i][2])) {
            Answer.push_back(UM[i]);
        }
    }
    if ((int)Answer.size() >= 2) {
        cout << "?\n";
    }
    else if ((int)Answer.size() == 1) {
        cout << Answer[0] << "\n";
    }
    else {
        cout << "!\n";
    }
}

void input() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> T >> S;
        UM[i] = S;
        for (int j = 0; j < 7; j++) {
            cin >> Sound[i][j];
        }
    }
    for (int i = 0; i < M; i++) {
        Vec.clear();
        Vec.resize(3);
        cin >> Vec[0] >> Vec[1] >> Vec[2];
        find_Answer();
    }
}

int main() {
    FASTIO
    input();

    return 0;
}