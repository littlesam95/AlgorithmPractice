#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int answer = 0;
bool visited[50] = { false, };

int solution(string begin, string target, vector<string> words) {
    queue<pair<string, int> > q;
    q.push(make_pair(begin, 0));
    
    while (!q.empty()) {
        string now_str = q.front().first;
        int now_count = q.front().second;
        q.pop();
        
        if (now_str == target) {
            answer = now_count;
            break;
        }
        
        for (int i = 0; i < words.size(); i++) {
            if (!visited[i]) {
                int diff = 0;
                for (int j = 0; j < words[i].size(); j++) {
                    if (now_str[j] != words[i][j]) {
                        diff++;
                    }
                }
                if (diff == 1) {
                    visited[i] = true;
                    q.push(make_pair(words[i], now_count + 1));
                }
            }
        }
    };
    
    return answer;
}