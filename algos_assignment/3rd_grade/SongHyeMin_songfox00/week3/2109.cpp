#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

priority_queue<int, vector<int>, greater<int> > pq;
vector<pair<int, int>>v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);

	int n;
	cin >> n;
	
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> b >> a;
		v.push_back({ a,b });
	}

	sort(v.begin(), v.end());

	int res=0;
	for (int i = 0; i < v.size(); i++) {
		res += v[i].second;
		pq.push(v[i].second);

		if (pq.size() > v[i].first) {
			res -= pq.top();
			pq.pop();
		}
	}
	cout << res;
	return 0;
}
