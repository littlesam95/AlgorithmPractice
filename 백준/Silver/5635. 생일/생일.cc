#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 101

using namespace std;
struct INFO {
	string Name;
	int Day;
	int Month;
	int Year;
	bool operator < (INFO A) {
		if (Year == A.Year) {
			if (Month == A.Month) {
				return (Day < A.Day);
			}
			return (Month < A.Month);
		}
		return (Year < A.Year);
	}
};

int N;
vector<INFO> Student;

int main() {
	FIRST;
	cin >> N;
	Student.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> Student[i].Name >> Student[i].Day >> Student[i].Month >> Student[i].Year;
	}
	sort(Student.begin(), Student.end());
	cout << Student[N - 1].Name << "\n";
	cout << Student[0].Name << "\n";

	return 0;
}