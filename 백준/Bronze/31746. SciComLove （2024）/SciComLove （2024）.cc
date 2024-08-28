#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N;

void input() {
    cin >> N;
    if (N % 2 == 0) {
        cout << "SciComLove\n";
    }
    else {
        cout << "evoLmoCicS\n";
    }
}

int main() {
    FASTIO
    input();

    return 0;
}