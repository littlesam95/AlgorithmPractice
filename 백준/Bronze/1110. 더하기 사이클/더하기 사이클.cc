#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int N, S;
int answer = 0;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> N;
    S = N;
    do {
        int A = S / 10;
        int B = S % 10;
        int tmp = A + B;
        int C = tmp % 10;
        S = (B * 10) + C;
        answer++;
    } while (S != N);
    cout << answer << "\n";
    
    return 0;
}