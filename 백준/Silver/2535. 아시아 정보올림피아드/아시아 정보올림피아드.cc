#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 101

using namespace std;
struct INFO {
    int Nation;
    int Number;
    int Score;
};

int N;
vector<INFO> vec;
vector<pair<int, int> > answer;
int Medal[MAX];

bool comp(INFO A, INFO B) {
    return (A.Score > B.Score);
}

int main() {
	FIRST;
    cin >> N;
    vec.resize(N + 1);
    for (int i = 0; i < N; i++) {
        cin >> vec[i].Nation >> vec[i].Number >> vec[i].Score;
    }
    sort(vec.begin(), vec.end(), comp);
    for (int i = 0; i < N; i++) {
        if (Medal[vec[i].Nation] < 2) {
            answer.push_back(make_pair(vec[i].Nation, vec[i].Number));
            Medal[vec[i].Nation]++;
        }
    }
    for (int i = 0; i < 3; i++) {
        cout << answer[i].first << " " << answer[i].second << "\n";
    }
    
	return 0;
}