#include <iostream>
#include <string>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <ctime>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 1001
#define LL long long
#define INF 1e9

using namespace std;
int T, N, M;
int A[MAX], B[MAX];
vector<int> SumA, SumB;
LL Answer = 0;

void Input() {
	cin >> T;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	cin >> M;
	for (int i = 1; i <= M; i++) {
		cin >> B[i];
	}
}

void Settings() {
	for (int i = 1; i <= N; i++) {
		int Tmp = A[i];
		SumA.push_back(Tmp);
		for (int j = i + 1; j <= N; j++) {
			Tmp += A[j];
			SumA.push_back(Tmp);
		}
	}
	for (int i = 1; i <= M; i++) {
		int Tmp = B[i];
		SumB.push_back(Tmp);
		for (int j = i + 1; j <= M; j++) {
			Tmp += B[j];
			SumB.push_back(Tmp);
		}
	}
	sort(SumB.begin(), SumB.end());
	for (int i = 0; i < SumA.size(); i++) {
		int Rest = T - SumA[i];
		int Up = upper_bound(SumB.begin(), SumB.end(), Rest) - SumB.begin();
		int Same = lower_bound(SumB.begin(), SumB.end(), Rest) - SumB.begin();
		Answer += Up - Same;
	}
}

void Find_Answer() {
	cout << Answer << "\n";
}

int main() {
	FASTIO
	Input();
	Settings();
	Find_Answer();

	return 0;
}