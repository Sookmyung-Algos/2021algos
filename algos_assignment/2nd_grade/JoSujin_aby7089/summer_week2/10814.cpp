#include <iostream>
#include <algorithm>
#include <string> //string 입력받기 위해 필요
#include <queue>
#include <vector>
using namespace std;
vector<pair<int, string>> q;

bool cmp(pair<int, string> a, pair<int, string> b) {  //들어온 순서 유지를 위한 코드
	return a.first < b.first;
}

int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0);
	int n, age;
	string name;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> age >> name;
		q.push_back({ age,name });
	}
	stable_sort(q.begin(), q.end(), cmp); //sort는 들어온 순서대로 정렬하지 않을 수도. stable 필요
	for (int i = 0; i < n; i++) {
		cout << q[i].first << " " << q[i].second << "\n";
	}
}
