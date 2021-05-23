//baekjoon 11650 좌표 정렬하기

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int n;
	cin >> n;	//점의 개수 입력

	vector<pair<int, int>> point;	//pair의 vector 생성
	pair<int, int> temp;

	for (int i = 0; i < n; i++) {
		cin >> temp.first >> temp.second;
		point.push_back(temp);
	}

	sort(point.begin(), point.end());
	for (int i = 0; i < n; i++)
		cout << point[i].first << ' ' << point[i].second << '\n';

	return 0;
}
