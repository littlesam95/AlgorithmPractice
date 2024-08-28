#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 100001

using namespace std;
long long N, M;
long long Edge_size = 0;
long long parent[MAX];
vector<pair<long long, long long> > Pos;
vector<pair<double, pair<long long, long long> > > vec;
double answer = 0;

void init() {
	for (int i = 1; i <= N; i++) {
		parent[i] = -1;
	}
}

long long Find(long long X) {
	if (parent[X] < 0) {
		return X;
	}
	return parent[X] = Find(parent[X]);
}

void Union_Set(long long X, long long Y) {
	long long P_X = Find(X);
	long long P_Y = Find(Y);
	if (P_X != P_Y) {
		parent[P_Y] = P_X;
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	Pos.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> Pos[i].first >> Pos[i].second;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			long long A = i;
			long long B = j;
			long long X = ((Pos[i].first - Pos[j].first) * (Pos[i].first - Pos[j].first));
			long long Y = ((Pos[i].second - Pos[j].second) * (Pos[i].second - Pos[j].second));
			double C = sqrt(X + Y);
			vec.push_back(make_pair(C, make_pair(A, B)));
		}
	}
	sort(vec.begin(), vec.end());
	init();
	for (int i = 0; i < M; i++) {
		long long A, B;
		cin >> A >> B;
		if (Find(A) != Find(B)) {
			Union_Set(A, B);
			Edge_size++;
		}
	}
	if (Edge_size >= N - 1) {
		cout << "0.00" << "\n";
		return 0;
	}
	for (int i = 0; i < vec.size(); i++) {
		long long A = vec[i].second.first;
		long long B = vec[i].second.second;
		long long C = vec[i].first;
		if (Find(A) != Find(B)) {
			Union_Set(A, B);
			answer += vec[i].first;
			if (++Edge_size == N - 1) {
				break;
			}
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << round(answer * 100) / (double)100 << "\n";

	return 0;
}