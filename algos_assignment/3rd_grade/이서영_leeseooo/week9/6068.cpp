#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n;
int ans = 987654321;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	vector<pair<int,int>>v;
	for (int i = 0; i < n; i++) {
		int t, s;
		cin >> t >> s;
		v.push_back({ s,t });
	}
	sort(v.begin(), v.end());
	for (int i = n - 1; i >= 0; i--) {
		ans = min(ans, v[i].first);
		ans -= v[i].second;
	}
	if (ans < 0)cout << -1;
	else cout << ans;
}
