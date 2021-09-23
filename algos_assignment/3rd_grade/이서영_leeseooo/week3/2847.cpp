#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
#include<cstring>
using namespace std;
int main() {
	int n;
	vector<int>v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int s;
		cin >> s;
		v.push_back(s);
	}
	int ans = 0;
	for (int i = n - 1; i > 0; i--) {
		while (v[i] <= v[i - 1]) {
			v[i-1]--;
			ans++;
		}
	}
	cout << ans;
}
