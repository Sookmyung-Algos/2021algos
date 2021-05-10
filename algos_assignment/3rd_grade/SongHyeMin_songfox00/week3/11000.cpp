#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	priority_queue<int, vector<int>, greater<int> >pq;
	vector<pair<int, int>> v;

	int n, a, b;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());
	pq.push(v[0].second);

	for (int i = 1; i < v.size(); i++) {
		if (pq.top() <= v[i].first) {
			pq.pop();
			pq.push(v[i].second);
		}
		else
			pq.push(v[i].second);
	}
	cout << pq.size() << '\n';
}
