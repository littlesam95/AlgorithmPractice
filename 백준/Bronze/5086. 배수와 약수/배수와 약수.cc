#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int A, B;
bool Flag;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    
    while (1) {
        Flag = true;
        cin >> A >> B;
        if ((A == 0) && (B == 0)) {
            break;
        }
        if (A < B) {
            Flag = false;
            swap(A, B);
        }
        if (A % B == 0) {
            if (Flag) {
                cout << "multiple\n";
            }
            else {
                cout << "factor\n";
            }
        }
        else {
            cout << "neither\n";
        }
    };
    
    return 0;
}