#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int X1, Y1, X2, Y2, X3, Y3;
int X, Y;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> X1 >> Y1;
    cin >> X2 >> Y2;
    cin >> X3 >> Y3;
    if (X1 == X2) {
        X = X3;
    }
    else if (X1 == X3) {
        X = X2;
    }
    else {
        X = X1;
    }
    if (Y1 == Y2) {
        Y = Y3;
    }
    else if (Y1 == Y3) {
        Y = Y2;
    }
    else {
        Y = Y1;
    }
    cout << X << " " << Y << "\n";
    
    return 0;
}