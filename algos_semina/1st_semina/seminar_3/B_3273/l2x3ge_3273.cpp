#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	vector<int> v;
	int n, x, cnt = 0;
	cin >> n;

	for (int i = 0;i < n;i++) {
		int a;
		cin >> a;
		v.push_back(a);

	}
	cin >> x;
	sort(v.begin(), v.end());
	int l = 0, r = n - 1;
	while (l<r) {
		int result = v[l] + v[r];
		if (result > x)
			r--;
		else if (result < x)
			l++;
		else {
			l++; r--;
			cnt++;
		}
	}
	cout << cnt;
}
