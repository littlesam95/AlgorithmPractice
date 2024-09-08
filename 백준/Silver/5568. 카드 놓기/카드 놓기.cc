#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
int n, k;
string card[10];
unordered_set<string> us;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	cin >> k;
	for (int i = 0; i < n; i++) {
		cin >> card[i];
	}
    
	if (k == 2) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if ((i == j)) {
					continue;
				}
				else {
					string tmp;
					tmp = card[i] + card[j];
					us.insert(tmp);
				}
			}
		}
	}
	else if (k == 3) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					if ((i == j) | (i == k) || (j == k) || ((i == j) && (j == k))) {
						continue;
					}
					else {
						string tmp;
						tmp = card[i] + card[j] + card[k];
						us.insert(tmp);
					}
				}
			}
		}
	}
	else if (k == 4) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					for (int l = 0; l < n; l++) {
						if ((i == j) | (i == k) || (i == l) || (j == k) || (j == l) || (k == l) 
							|| ((i == j) && (j == k)) || ((i == j) && (j == l)) || ((j == k) && (k == l))
							|| ((i == j) && (j == k) && (k == l))) {
							continue;
						}
						else {
							string tmp;
							tmp = card[i] + card[j] + card[k] + card[l];
							us.insert(tmp);
						}
					}
				}
			}
		}
	}
	cout << us.size() << "\n";

	return 0;
}