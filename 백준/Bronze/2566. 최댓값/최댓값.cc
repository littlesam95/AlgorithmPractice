#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MAX 10
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int MAP[MAX][MAX];
int AnswerM, AnswerY, AnswerX;

void input() {
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            cin >> MAP[i][j];
            if (AnswerM <= MAP[i][j]) {
                AnswerM = MAP[i][j];
                AnswerY = i;
                AnswerX = j;
            }
        }
    }
}

void find_Answer() {
    cout << AnswerM << "\n" << AnswerY << " " << AnswerX << "\n";;
}

int main() {
    FASTIO
    input();
    find_Answer();

    return 0;
}