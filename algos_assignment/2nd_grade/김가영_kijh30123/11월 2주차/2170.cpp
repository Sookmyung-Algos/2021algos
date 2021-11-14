#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<pair<int, int>> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i<n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());

	int ans = 0;

	int start = v[0].first, end = v[0].second;

	for (int i = 1; i<n; i++) {
		int x1 = v[i].first, x2 = v[i].second;
		if (end>=x1) { //한번에 그릴 수 있음
			end = max(end, x2);
		}
		else {
			ans += end - start; //현재까지 그린 길이
			start = x1, end = x2; //새로지정
		}
	}

	ans += end - start; //마지막 선 더하기


	cout << ans;

	return 0;
}
