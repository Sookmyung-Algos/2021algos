#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool cmp(pair<pair<int, int>,int>a, pair<pair<int, int>,int>b) {
	if (a.first.first == b.first.first)
		return a.first.second > b.first.second;
	return a.first.first < b.first.first;
}

bool include[500001] = { false, };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);

	vector<pair<pair<int, int>, int>>v1;
	vector<pair<pair<int, int>, int>>v2;

	int n, m;
	cin >> n >> m;

	int a, b, min_s=1000000001, max_e=-1;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		if (a < b)
			v1.push_back({ { a,b }, i+1 });
		else {
			min_s = min(min_s, a);
			max_e = max(max_e, b);
			b += n;
			v2.push_back({ { a,b },i+1 });
		}
	}

	sort(v1.begin(), v1.end(), cmp);
	sort(v2.begin(), v2.end(), cmp);

	int end = 0;

	for (int i = 0; i < v1.size(); i++) {
		if (v1[i].first.first >= min_s || v1[i].first.second <= max_e)
			include[v1[i].second] = true;
		else if(v1[i].first.second <= end)
			include[v1[i].second] = true;
		else
			end = v1[i].first.second;	
	}

	end = 0;
	for (int i = 0; i < v2.size(); i++) {
		if (v2[i].first.second <= end)
			include[v2[i].second] = true;
		else
			end = v2[i].first.second;
	}

	for (int i = 1; i <= m; i++) {
		if (!include[i])
			cout << i << ' ';
	}
	return 0;
}
