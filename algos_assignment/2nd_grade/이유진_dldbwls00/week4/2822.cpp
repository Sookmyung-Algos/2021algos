#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int main() {
	vector<pair<int, int>> v;
	int score;
	for (int i = 0; i < 8; i++) {
		cin >> score;
		v.push_back(pair<int, int>(score, i));
	}
	sort(v.begin(), v.end());

	int sum = 0;
	for (int i = 3; i < 8; i++)	sum += v[i].first; // sum 출력
	cout << sum << '\n';
	
	vector<int> num;
	for (int i = 3; i < 8; i++)	num.push_back(v[i].second + 1); // 인덱스 넣기
	sort(num.begin(), num.end());
	for (int i = 0; i < 5; i++)	cout << num[i] << ' '; // 인덱스 출력

	return 0;
}
