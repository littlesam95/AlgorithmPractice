#include <iostream>
#include <algorithm>

using namespace std;
int N, M, K;

int main() {
    cin >> N >> M >> K;
    if ((N % (K - M)) == 0) {
        cout << (N / (K - M)) << "\n";
    }
    else {
        cout << (N / (K - M)) + 1 << "\n";
    }
}