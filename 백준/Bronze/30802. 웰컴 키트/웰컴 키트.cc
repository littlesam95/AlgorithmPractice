#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, T, P;
vector<int> Tshirts(6);
int AnswerA, AnswerB, AnswerC;

void input() {
    cin >> N;
    for (int i = 0; i < 6; i++) {
        cin >> Tshirts[i];
    }
    cin >> T >> P;
    for (int i = 0; i < 6; i++) {
        int Now = Tshirts[i];
        if (Now % T == 0) {
            AnswerA += (Now / T);
        }
        else {
            AnswerA += ((Now / T) + 1);
        }
    }
    AnswerB = (N / P);
    AnswerC = (N % P);
    cout << AnswerA << "\n";
    cout << AnswerB << " " << AnswerC << "\n";
}

int main() {
    FASTIO
    input();

    return 0;
}