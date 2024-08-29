#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
int N, W, H;
double S;

void find_Answer(int I) {
    if ((double)I <= S) {
        cout << "DA\n";
    }
    else {
        cout << "NE\n";
    }
}

void input() {
    cin >> N >> W >> H;
    S = sqrt((W * W) + (H * H));
    for (int i = 0; i < N; i++) {
        int I;
        cin >> I;
        find_Answer(I);
    }
}

int main(void) {
    input();
    
    return 0;
}