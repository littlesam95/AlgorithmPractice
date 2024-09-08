#include <iostream>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

using namespace std;
int L, A, B, C, D;

int main() {
    FIRST
    cin >> L >> A >> B >> C >> D;
    int X = A / C;
    int Y = B / D;
    if (A % C > 0) {
        X++;
    }
    if (B % D > 0) {
        Y++;
    }
    int W = max(X, Y);
    cout << L - W << "\n";
    
    return 0;
}