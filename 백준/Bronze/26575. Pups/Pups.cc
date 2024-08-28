#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N;
double D, F, P;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> D >> F >> P;

        cout << fixed;
        cout.precision(2);
        cout << "$" << D * F * P << "\n";
    }
}

int main() {
    FASTIO
    input();

    return 0;
}