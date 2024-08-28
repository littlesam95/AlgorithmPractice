#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int A, B, C;
int answer;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> A >> B >> C;
    if (B >= C) {
        cout << -1 << "\n";
        return 0;
    }
    answer = A / (C - B);
    cout << answer + 1 << "\n";
    
    return 0;
}