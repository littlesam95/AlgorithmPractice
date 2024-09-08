#include <iostream>
#include <algorithm>

using namespace std;
int N0;
int IDX = 1;

void find_Answer() {
    if ((N0 * 3) % 2 == 0) {
        cout << IDX++ << ". even " << N0 / 2 << "\n";
    }
    else {
        cout << IDX++ << ". odd " << (N0 - 1) / 2 << "\n";
    }
}

void input() {
    while (1) {
        cin >> N0;
        if (N0 == 0) {
            break;
        }
        find_Answer();
    };
}

int main(void) {
    input();
    
    return 0;
}