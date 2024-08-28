#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
unordered_map<int, int> UM;
unordered_map<int, int>::iterator IT;
int Sum = 0;
vector<pair<int, int> > Vec;

void input() {
    for (int i = 0; i < 10; i++) {
        int N;
        cin >> N;
        UM[N]++;
        Sum += N;
    }
}

void find_Answer() {
    cout << Sum / 10 << "\n";
    for (IT = UM.begin(); IT != UM.end(); IT++) {
        Vec.push_back(make_pair(IT->second, IT->first));
    }
    sort(Vec.begin(), Vec.end());
    cout << Vec[Vec.size() - 1].second << "\n";
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    input();
    find_Answer();
    
	return 0;
}