#include <iostream>
#include <algorithm>

using namespace std;
int N, M;

void input() {
    cin >> N;
    while (1) {
        cin >> M;
        if (M == 0) {
            break;
        }
        if (M % N == 0) {
            cout << M << " is a multiple of " << N << ".\n";
        }
        else {
            cout << M << " is NOT a multiple of " << N << ".\n";
        }
    };
}

int main(void) {
    input();
    
    return 0;
}