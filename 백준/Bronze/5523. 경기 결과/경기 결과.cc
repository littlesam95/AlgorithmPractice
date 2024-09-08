#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, A, B;
int AnswerA, AnswerB;

void input() {
    cin >> N;
    while (N--) {
        cin >> A >> B;
        if (A > B) {
            AnswerA++;
        }
        else if (A < B) {
            AnswerB++;
        }
    };
    cout << AnswerA << " " << AnswerB << "\n";
}

int main() {
    FASTIO
    input();

    return 0;
}