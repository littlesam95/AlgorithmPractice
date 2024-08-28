#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, C;
double A, Sum;
string T;
unordered_map<string, double> UM;

void input() {
    cin >> N >> C;
    for (int i = 0; i < N; i++) {
        cin >> A >> T;
        UM[T] += A;
        Sum += A;
    }

    cout << Sum << "\n" << UM["bedroom"] << "\n";
    cout << fixed;
    cout.precision(6);
    cout << (Sum - UM["balcony"] / 2) * C << "\n";
}

int main() {
    FASTIO
    input();

    return 0;
}