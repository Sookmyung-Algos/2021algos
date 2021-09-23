#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;
vector <pair<int, int>> v;
int ans[51];

int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0);
	int n, x, y;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		v.push_back(make_pair(x, y));
		ans[i] = 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (v[i].first < v[j].first&&v[i].second < v[j].second)
				ans[i]++;
		}
	}
	for (int i = 0; i < n; i++)
		cout << ans[i] << " ";
}
