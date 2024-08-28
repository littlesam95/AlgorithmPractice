#include <iostream>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

using namespace std;
double H, W;

void input() {
    cin >> H;
    cin >> W;
    cout << (int)((min(H, W) / 2) * 100) << "\n";
}

int main() {
    FASTIO
    input();
        
    return 0;
}