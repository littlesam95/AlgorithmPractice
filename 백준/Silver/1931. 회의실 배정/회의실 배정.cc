#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
int N;
int res = 0;

struct Talk {
	int start;
	int end;
};

bool comp(Talk A, Talk B) {
	if (A.end < B.end) {
		return true;
	}
	else if (A.end == B.end) {
		if (A.start < B.start) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

void calc(vector<Talk> vec, int& res) {
	int nowOrder = 0;
	int sum = 1;

	for (int i = 1; i < N; i++) {
		if (vec[nowOrder].end <= vec[i].start) {
			sum++;
			nowOrder = i;
		}
	}

	res = sum;
}

int main() {
	cin >> N;
	vector<Talk> vec(N);
	for (int i = 0; i < N; i++) {
		cin >> vec[i].start >> vec[i].end;
	}

	sort(vec.begin(), vec.end(), comp);
	calc(vec, res);

	cout << res;
    
	return 0;
}