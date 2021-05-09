#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int main() {
	vector<pair<int, int>>v;
	int cnt = 0;
	int n, p;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p;
		v.push_back({ p, i });
	}
	sort(v.begin(), v.end());
	int tmp = 0;
	for (int i = 0; i < n; i++) {
		cnt += v[i].first + tmp;
		tmp += v[i].first;
	}
	cout << cnt;
}
