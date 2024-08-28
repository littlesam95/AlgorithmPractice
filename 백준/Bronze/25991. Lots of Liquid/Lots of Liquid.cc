#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N;
double C;
double Answer;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> C;
        Answer += pow(C, 3);
    }

    Answer = pow(Answer, 1.0 / 3);
    cout << fixed;
    cout.precision(6);
    cout << Answer << "\n";
}

int main() {
    FASTIO
    input();

    return 0;
}