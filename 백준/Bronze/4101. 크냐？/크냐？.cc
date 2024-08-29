#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0);

using namespace std;
int A, B;

void input() {
    while (1) {
        cin >> A >> B;
        if ((A == 0) && (B == 0)) {
            break;
        }
        if (A > B) {
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }
    };
}

int main() {
    FASTIO
    input();

    return 0;
}