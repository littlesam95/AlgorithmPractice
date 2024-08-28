#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N, K;
int plug[101];
vector<int> device;
int answer = 0;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		int n;
		cin >> n;
		device.push_back(n);
	}

	for (int i = 0; i < K; i++) {
		// 해당 기기에 플러그기 꽂혀있는가
		bool plugged = false;
		for (int j = 0; j < N; j++) {
			if (plug[j] == device[i]) {
				plugged = true;
				break;
			}
		}
		if (plugged) {
			continue;
		}
		// 플러그에 빈 곳이 있는가
		bool blank = false;
		for (int j = 0; j < N; j++) {
			if (!plug[j]) {
				plug[j] = device[i];
				blank = true;
				break;
			}
		}
		if (blank) {
			continue;
		}
		// 플러그에 빈 곳이 없는 경우
		int idx, device_idx = -1;
		for (int j = 0; j < N; j++) {
			int last_idx = 0;
			for (int k = i + 1; k < K; k++) {
				if (plug[j] == device[k]) {
					break;
				}
				last_idx++;
			}
			if (last_idx > device_idx) {
				idx = j;
				device_idx = last_idx;
			}
		}
		answer++;
		plug[idx] = device[i];
	}

	cout << answer << "\n";

	return 0;
}

// 너무 어려워서 https://jaimemin.tistory.com/759 참고함.