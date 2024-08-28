#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int R, B;

void input() {
    cin >> R >> B;
}

void find_Answer() {
    int T = 1;
    while (1) {
        if (B % T == 0) {
            int U = B / T;
            if ((T + 2) * (U + 2) == (R + B)) {
                int L = T + 2;
                int W = U + 2;
                if (L >= W) {
                    cout << L << " " << W << "\n";
                }
                else {
                    cout << W << " " << L << "\n";
                }
                return;
            }
        }
        T++;
    };
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    input();
    find_Answer();
    
	return 0;
}