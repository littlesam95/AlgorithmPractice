#include <iostream>
#include <string>
#include <cmath>
#include <stack>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 101

using namespace std;
int N, C;
int MAP[MAX];
bool visited[MAX];
vector<int> Picture;

int main() {
	FIRST
	cin >> N;
	cin >> C;
	for (int i = 0; i < C; i++) {
		int Student;
		cin >> Student;
		if (Picture.size() < N) {
			if (visited[Student]) {
				MAP[Student]++;
			}
			else {
				MAP[Student]++;
				visited[Student] = true;
				Picture.push_back(Student);
			}
		}
		else if (Picture.size() == N) {
			if (visited[Student]) {
				MAP[Student]++;
			}
			else {
				int Cur_Rec = MAP[Picture[0]];
				int Cur_Student = 0;
				for (int j = 1; j < Picture.size(); j++) {
					if (MAP[Picture[j]] < Cur_Rec) {
						Cur_Rec = MAP[Picture[j]];
						Cur_Student = j;
					}
					else if (MAP[Picture[j]] == Cur_Rec) {
						Cur_Student = min(Cur_Student, j);
					}
				}
				MAP[Picture[Cur_Student]] = 0;
				visited[Picture[Cur_Student]] = false;
				Picture.erase(Picture.begin() + Cur_Student);
				MAP[Student]++;
				Picture.push_back(Student);
				visited[Student] = true;
			}
		}
	}
	sort(Picture.begin(), Picture.end());
	for (int i = 0; i < Picture.size(); i++) {
		cout << Picture[i] << " ";
	}
	cout << "\n";

	return 0;
}