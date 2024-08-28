#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int T, A, B;

int GCD(int A, int B) {
    int R;
    while (1) {
        R = A % B;
        if (R == 0) {
            return B;
        }
        A = B;
        B = R;
    };
}

int LCM(int A, int B) {
    return (A * B) / GCD(A, B);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> T;
    while (T--) {
        cin >> A >> B;
        cout << LCM(A, B) << "\n";
    };
    
    return 0;
}