#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MAX 11
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, M;
int MAP[MAX];
double Avg;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> M;
        MAP[M]++;
        Avg += (double)M;
    }
    Avg /= (double)N;
    if (MAP[3] > 0) {
        cout << "None\n";
    }
    else if (MAP[5] == N) {
        cout << "Named\n";
    }
    else if (Avg >= 4.5) {
        cout << "High\n";
    }
    else {
        cout << "Common\n";
    }
}

int main() {
    FASTIO
    input();

    return 0;
}