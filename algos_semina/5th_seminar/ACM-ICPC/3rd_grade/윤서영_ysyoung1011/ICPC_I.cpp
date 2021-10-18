#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, pair<int, int>> piii;
vector<piii> arr;

bool cmp(piii a, piii b) {
	if (a.second.first == b.second.first) {
		if (a.second.second == b.second.second)
			return a.first < b.first;
		return a.second.second < b.second.second;
	}
	return a.second.first < b.second.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		arr.push_back({ a,{ b*c*d, b + c + d } });
	}
	sort(arr.begin(), arr.end(), cmp);

	for (int i = 0; i < 3; i++) {
		cout << arr[i].first << " ";
	}

	return 0;
}
