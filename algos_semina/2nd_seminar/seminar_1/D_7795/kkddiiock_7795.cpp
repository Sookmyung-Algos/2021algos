#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int binary(int y, vector<int>& v) {
	int left = 0, right = v.size() - 1,mid;
	int lowerIdx = 0;
	while (left <= right) {
		mid = (left + right) / 2;
		if (y > v[mid])left = mid + 1;
		else right = mid - 1;
	}
	return left;
}
int main() {
	int t, n, m,x,ans;
	cin >> t;
	while (t--) {
		ans = 0;
		cin >> n >> m;
		vector<int>a(n), b(m);
		for(int i=0;i<n;i++) {
			cin >> a[i];
		}
		for (int i = 0; i < m; i++) {
			cin >> b[i];
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		for (int i = 0; i < n; i++)
			ans += binary(a[i], b);
		cout << ans << endl;
	}
}
