#include <iostream> 
#include <vector>
#include <queue>
#include<algorithm>
using namespace std;
int main(void) {

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(0);

	vector<pair<int, int>> v;
	priority_queue<int, vector<int>, greater<int>> pq;
	int n;
	cin >> n;

	for (int i = 0;i < n;i++) {
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(b, a));
	}
	sort(v.begin(), v.end());
	int ans = 0;
	for (int j = 0;j < v.size();j++) {
		ans += v[j].second;
		pq.push(v[j].second);

		if (pq.size() > v[j].first) {
			ans -= pq.top();
			pq.pop();
		}
	}
	cout << ans << "\n";

}
