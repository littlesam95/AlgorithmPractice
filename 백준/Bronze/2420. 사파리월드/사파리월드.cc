#include <iostream>
#include <cmath>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

using namespace std;
long long N, M;

int main() {
    FIRST
    cin >> N >> M;
    cout << abs(N - M) << "\n";
    
    return 0;
}