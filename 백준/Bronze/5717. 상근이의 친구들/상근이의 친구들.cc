#include <iostream>
#include <algorithm>

using namespace std;
int N, M, Answer;

void input() {
    while (1) {
        cin >> N >> M;
        if ((N == 0) && (M == 0)) {
            break;
        }
        cout << N + M << "\n";
    };
}

int main(void) {
    input();
    
    return 0;
}