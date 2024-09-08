#include <iostream>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

using namespace std;
int A, B, C, D;

int main() {
    FIRST
    cin >> A >> B >> C >> D;
    int sum = A + B + C + D;
    cout << sum / 60 << "\n";
    cout << sum % 60 << "\n";
    
    return 0;
}