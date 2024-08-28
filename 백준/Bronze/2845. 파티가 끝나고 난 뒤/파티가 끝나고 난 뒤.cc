#include <iostream>
#include <string>
#include <algorithm>
#define MAX 100001

using namespace std;
int L, P;
int Arr[MAX];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> L >> P;
    for (int i = 0; i < 5; i++) {
        cin >> Arr[i];
    }
    for (int i = 0; i < 5; i++) {
        int answer = Arr[i] - (L * P);
        cout << answer << " ";
    }
    cout << "\n";
    
    return 0;
}