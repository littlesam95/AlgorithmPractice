#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
int N, M;
map<string, int> hear;
vector<string> result;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	char name[21];
	for (int i = 0; i < N; i++) {
		cin >> name;
		string str = name;
		hear.insert(pair<string, int>(str, 1));
	}

	int index = 0;
	for (int i = 0; i < M; i++) {
		cin >> name;
		string str = name;
		hear[name]++;
		if (hear[name] == 2) {
			result.push_back(name);
			index++;
		}
	}

	sort(result.begin(), result.end());

	cout << index << "\n";
	for (int i = 0; i < index; i++) {
		cout << result[i] << "\n";
	}

	return 0;
}