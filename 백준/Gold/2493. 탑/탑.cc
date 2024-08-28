#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 500001

using namespace std;
int N;
int top = 0;
int idx = 0;
int arr[MAX];
stack<pair<int, int> > s;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (s.empty()) {
			s.push(make_pair(arr[i], i + 1));
			cout << i << " ";
			top = arr[i];
			idx = i;
		}
		else {
			if (s.top().first < arr[i]) {
				while (s.top().first < arr[i]) {
					s.pop();
					if (s.empty()) {
						break;
					}
				};
				if (s.empty()) {
					cout << 0 << " ";
				}
				else {
					cout << s.top().second << " ";
				}
			}
			else {
				cout << i << " ";
			}
			s.push(make_pair(arr[i], i + 1));
		}
	}
	cout << "\n";

	return 0;
}