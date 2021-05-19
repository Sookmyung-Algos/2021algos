#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int main() {
	int n, k, a;
	int index = 0;
	vector<int>v;

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a > k) 
			continue;
		v.push_back(a);
	}
	sort(v.begin(), v.end(), greater<int>());
	int cnt = 0, res = 0;
	for (int i = 0; i < v.size(); i++) {
			cnt += k / v[i];
			res = k % v[i];
			k %= v[i];
	}
	cout << cnt;
}
