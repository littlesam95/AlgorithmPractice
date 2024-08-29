#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
double N;

void find_Answer() {
    cout << fixed;
    cout.precision(2);
    cout << "Objects weighing " << N << " on Earth will weigh " << (N * 0.167) << " on the moon.\n";
}

void input() {
    while (1) {
        cin >> N;
        if (N < 0) {
            break;
        }
        find_Answer();
    };
}

int main() {
    FASTIO
    input();

    return 0;
}