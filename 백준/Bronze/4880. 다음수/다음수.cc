#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
int A[3];

void input() {
    while (1) {
        cin >> A[0] >> A[1] >> A[2];
        if ((A[0] == 0) && (A[1] == 0) && (A[2] == 0)) {
            break;
        }
        if ((A[1] - A[0]) == (A[2] - A[1])) {
            cout << "AP " << A[2] + A[2] - A[1] << "\n";
        }
        else {
            if (abs(A[0]) < abs(A[1])) {
                cout << "GP " << A[2] * (A[2] / A[1]) << "\n";
            }
            else {
                sort(A, A + 3);
                cout << "GP " << A[0] / (A[2] / A[1]) << "\n";
            }
        }
    };
}

int main(void) {
    input();
    
    return 0;
}