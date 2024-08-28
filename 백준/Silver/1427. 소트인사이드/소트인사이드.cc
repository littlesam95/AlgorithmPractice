#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
string N;

bool comp(char A, char B) {
    return (A > B);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> N;
    sort(N.begin(), N.end(), comp);
    cout << N << "\n";
    
    return 0;
}