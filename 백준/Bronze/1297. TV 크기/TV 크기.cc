#include <iostream>
#include <cmath>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

using namespace std;
int D, H, W;

int main() {
    FIRST
    cin >> D >> H >> W;
    double MOD = sqrt(H * H + W * W);
    double answer1 = D * H / MOD;
    double answer2 = D * W / MOD;
    cout << (int)answer1 << " " << (int)answer2 << "\n";
    
    return 0;
}