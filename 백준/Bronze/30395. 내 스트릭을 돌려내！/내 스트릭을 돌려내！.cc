#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MAX 1001
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, P;
int Next_Freeze, Max_Streak;
int Answer;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> P;
        if (P == 0) {
            if (Next_Freeze <= i) {
                Next_Freeze = i + 2;
            }
            else {
                Answer = max(Answer, Max_Streak);
                Max_Streak = 0;
            }
        }
        else {
            Max_Streak++;
        }
    };
    Answer = max(Answer, Max_Streak);

    cout << Answer << "\n";
}

int main() {
    FASTIO
    input();

    return 0;
}