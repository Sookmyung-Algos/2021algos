#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<pair<int, int>, string> a, pair<pair<int, int>, string> b) {
	if (a.first.second != b.first.second)
		return a.first.second < b.first.second;
	return a.first.first < b.first.first;
}

int main() {
	int n, age;
	string name;
	vector<pair<pair<int,int>, string>> member; // 순서, 나이, 이름

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> age >> name;
		member.push_back({ {i,age},name });
	}
	sort(member.begin(), member.end(), compare);


	for (int i = 0; i < n; i++)
		cout << member[i].first.second << " " << member[i].second << "\n";
}
