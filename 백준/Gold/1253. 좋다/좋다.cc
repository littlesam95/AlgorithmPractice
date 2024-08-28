#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <algorithm>
#define MAX 2001
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N;
int A[MAX];
unordered_map<int, int> UM;
set<int> S;
set<int>::iterator IT;
int Answer;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        UM[A[i]]++;
    }
}

void settings() {
    for (int i = 0; i < N; i++) {
        for (int j = (i + 1); j < N; j++) {
            if (UM[A[i] + A[j]] > 0) {
                int Count = UM[A[i] + A[j]];
                if (A[i] + A[j] == A[i]) {
                    Count--;
                }
                if (A[i] + A[j] == A[j]) {
                    Count--;
                }
                if (Count > 0) {
                    S.insert(A[i] + A[j]);
                }
            }
        }
    }
    for (IT = S.begin(); IT != S.end(); IT++) {
        int Now = *IT;
        Answer += UM[Now];
    }
}

void find_Answer() {
    cout << Answer << "\n";
}

int main() {
    FASTIO
    input();
    settings();
    find_Answer();

    return 0;
}