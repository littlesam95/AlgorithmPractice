#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#define PI2 2

using namespace std;
const double PI = acos(-1.0);
double R, answer1, answer2;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> R;
    answer1 = R * R * PI;
    answer2 = R * R * PI2;
    cout << fixed;
    cout.precision(6);
    cout << answer1 << "\n";
    cout << answer2 << "\n";
    
    return 0;
}