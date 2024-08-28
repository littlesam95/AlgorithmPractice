#include <iostream>
#include <string>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

using namespace std;
int N, F;
string answer = "";

int main() {
    FIRST
    cin >> N;
    cin >> F;
    int R = N % 100;
    N -= R;
    while (1) {
        if (N % F == 0) {
            string tmp = to_string(N);
            int size = tmp.size();
            answer = tmp.substr(size - 2);
            break;
        }
        N++;
    };
    cout << answer << "\n";
    
    return 0;
}