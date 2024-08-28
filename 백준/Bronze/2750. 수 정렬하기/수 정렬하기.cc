#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int N;
vector<int> answer;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        int X;
        cin >> X;
        answer.push_back(X);
    }
    sort(answer.begin(), answer.end());
    for (int i = 0; i < N; i++) {
        cout << answer[i] << "\n";
    }
    
    return 0;
}