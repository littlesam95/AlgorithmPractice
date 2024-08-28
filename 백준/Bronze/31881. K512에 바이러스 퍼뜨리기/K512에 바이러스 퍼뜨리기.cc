#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MAX 200001
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, Q, T, X;
string S;
bool Visited[MAX];
int Answer;

void input() {
    cin >> N >> Q;
    Answer = N;
    for (int i = 0; i < Q; i++) {
        cin >> T;
        if (T == 1) {
            cin >> X;
            if (!Visited[X]) {
                Answer--;
            }
            Visited[X] = true;
        }
        else if (T == 2) {
            cin >> X;
            if (Visited[X]) {
                Answer++;
            }
            Visited[X] = false;
        }
        else {
            cout << Answer << "\n";
        }
    }
}

int main() {
    FASTIO
    input();

    return 0;
}