#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);

	int t, n;
	cin >> t;

	while (t--) {
		vector<pair<int, int>>v;
		cin >> n;

		int a, b;
		for (int i = 0; i < n; i++) {
			cin >> a >> b;
			v.push_back({ a, b });
		}
		sort(v.begin(), v.end());

		int rank = v[0].second;
		int cnt = 1;
		for (int i = 1; i < v.size(); i++) {
			if (v[i].second < rank) {
				cnt++;
				rank = min(v[i].second, rank);
			}
		}

		cout << cnt << '\n';
	}
	
	return 0;
}
