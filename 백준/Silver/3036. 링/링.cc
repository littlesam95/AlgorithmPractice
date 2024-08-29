#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int N;
vector<int> vec;

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

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        int X;
        cin >> X;
        vec.push_back(X);
    }
    for (int i = 1; i < N; i++) {
        int G = GCD(vec[0], vec[i]);
        cout << vec[0] / G << "/" << vec[i] / G << "\n";
    }
    
    return 0;
}