#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	vector<int>v;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	int cnt = 1, maxcnt = 1;
	for (int i = 1; i < n; i++) {
		if (v[i] >= v[i - 1])
			cnt++;
		else {
			cnt = 1;
		}
		maxcnt = max(cnt, maxcnt);
	}
	cnt = 1;
	for (int i = 1; i < n; i++) {
		if (v[i] <= v[i - 1])
			cnt++;
		else {
			cnt = 1;
		}
		maxcnt = max(cnt, maxcnt);
	}

	cout << maxcnt;

	return 0;
}
