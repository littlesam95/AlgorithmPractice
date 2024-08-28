#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N;
int T[3];
int Answer;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> T[0] >> T[1] >> T[2];
        bool Flag = true;

        int Solved = 0;
        for (int j = 0; j < 3; j++) {
            if (T[j] != -1) {
                Solved++;
            }
        }

        if (Solved == 0) {
            Flag = false;
        }
        
        for (int j = 0; j < 3; j++) {
            int NowT = T[j];
            if (NowT == -1) {
                continue;
            }
            for (int k = 0; k < j; k++) {
                if ((NowT < T[k]) || (T[k] == -1)) {
                    Flag = false;
                }
            }
            for (int k = (j + 1); k < 3; k++) {
                if ((T[k] != -1) && (NowT > T[k])) {
                    Flag = false;
                }
            }
        }

        if (Flag) {
            Answer++;
        }
    }
    cout << Answer << "\n";
}

int main() {
    FASTIO
    input();

    return 0;
}