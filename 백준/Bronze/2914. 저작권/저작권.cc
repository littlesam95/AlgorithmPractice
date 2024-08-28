#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int A, I;
int answer = 0;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> A >> I;
    answer = A * (I - 1) + 1;
    cout << answer << "\n";
    
    return 0;
}