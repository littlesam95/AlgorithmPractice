#include <iostream>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;
int N, M;
deque<int> dq;
int answer = 0;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        dq.push_back(i);
    }
    while (M--) {
        int X, idx;
        cin >> X;
        for (int i = 0; i < dq.size(); i++) {
            if(dq[i] == X) {
                idx = i;
                break;
            }
        }
        if (idx < dq.size() - idx) {
            while (1) {
                if (dq.front() == X) {
                    dq.pop_front();
                    break;
                }
                answer++;
                dq.push_back(dq.front());
                dq.pop_front();
            };
        }
        else {
            while (1) {
                if (dq.front() == X) {
                    dq.pop_front();
                    break;
                }
                answer++;
                dq.push_front(dq.back());
                dq.pop_back();
            };
        }
    };
    cout << answer << "\n";
    
    return 0;
}