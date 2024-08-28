#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, A;
priority_queue<double, vector<double>, greater<double> > PQ;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A;
        PQ.push(A);
    }
    for (int i = 0; i < (N - 1); i++) {
        double First = PQ.top();
        PQ.pop();
        double Second = PQ.top();
        PQ.pop();

        double Avg = (First + Second) / 2;
        PQ.push(Avg);
    }
    cout << fixed;
    cout.precision(6);
    cout << PQ.top() << "\n";
}

int main() {
    FASTIO
    input();

    return 0;
}