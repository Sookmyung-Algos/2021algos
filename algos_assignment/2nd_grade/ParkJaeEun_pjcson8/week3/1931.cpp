#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	vector<pair<int, int>> v;
	int n, start, end;
	int cnt = 1, out = 0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> start >> end;
		v.push_back({ end,start });
	}

	sort(v.begin(), v.end());

	for (int i = 1; i < n; i++) {
		if (v[out].first > v[i].second)
			continue;
		out = i;
		cnt++;
	}

	cout << cnt;
}
