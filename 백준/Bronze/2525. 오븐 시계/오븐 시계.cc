#include <iostream>
#include <cmath>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

using namespace std;
int A, B, C;
int H, M;

int main() {
    FIRST
    cin >> A >> B;
    cin >> C;
    int D = C / 60;
    int E = C % 60;
    H = A + D;
    M = B + E;
    if (M >= 60) {
        int F = M / 60;
        H += F;
        M -= (F * 60);
    }
    if (H >= 24) {
        H -= 24;
    }
    cout << H << " " << M << "\n";
    
    return 0;
}