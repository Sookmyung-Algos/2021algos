#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
using namespace std;
void init() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
}
bool compare(pair<int, int>& v1, pair <int, int>& v2) {
	return v1.second > v2.second;
}
int main() {
	init();
	vector <pair<int, int>>v;
	vector <int> arr(1001);
	int ans = 0;
	int n;
	cin >> n;
	int d, w;
	for (int i = 0; i < n; i++) {
		cin >> d >> w;
		v.push_back({ d,w });
	}
	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < n; i++) {
		for (int j = v[i].first;j > 0; j--) {
			if (v[i].second > arr[j]) {
				arr[j] = v[i].second;
				break;
			}
		}

	}
	
	for (int i = 0; i < 1001; i++) {
		ans += arr[i];
	}
	cout << ans;
	
	return 0;
}
