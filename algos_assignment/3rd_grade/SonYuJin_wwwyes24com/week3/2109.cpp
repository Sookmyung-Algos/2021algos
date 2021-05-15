#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	int n, p, d, ans = 0;
	vector<pair<int, int>> lec;
	priority_queue<int, vector<int>, greater<int>> list;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p >> d;
		lec.push_back({ d,p }); // 기한이 적은 순서대로 먼저 정렬하므로
	}
	sort(lec.begin(), lec.end());

	for (int i = 0; i < n; i++) {
		list.push(lec[i].second);
		ans += lec[i].second; // 총 금액
		if (lec[i].first < list.size()) { // 기한보다 하는 강연 수가 많으면
			ans -= list.top();
			list.pop();
		}
	}
	cout << ans;
}
