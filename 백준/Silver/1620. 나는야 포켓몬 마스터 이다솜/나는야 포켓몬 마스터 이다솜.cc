#include <iostream>
#include <string>
#include <string.h>
#include <map>
#include <algorithm>
#include <utility>

using namespace std;
int N, M; // 도감에 수록되어 있는 포켓몬의 개수, 맞춰야 하는 문제의 개수
map<string, int> pokemon;
string result[100001];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	char name[21];
	for (int number = 0; number < N; number++) {
		cin >> name;
		string str = name;
		pokemon.insert(pair<string, int>(str, number + 1));
		result[number] = str;
	}
	char ques[21];
	for (int number = 0; number < M; number++) {
		cin >> ques;
		if ((int(ques[0]) >= 65) && (int(ques[0]) <= 90)) { // 문제가 포켓몬 이름일 때
			cout << pokemon[ques] << "\n";
		}
		else if ((int(ques[0]) >= 48) && (int(ques[0]) <= 57)) { // 문제가 번호일 때
			string tmp = ques;
			cout << result[stoi(tmp) - 1] << "\n";
		}
	}

	return 0;
}