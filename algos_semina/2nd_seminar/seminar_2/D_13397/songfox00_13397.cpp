#include<iostream>
#include<vector>

using namespace std;

vector<int>v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;

	for(int i=0;i<n;i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	int left = 0;
	int right = 10001;
	while (left <= right) {
		int mid = (left + right) / 2;
		int min = v[0];
		int max = v[0];

		int res = 1;
		for (int i = 1; i < n; i++) {
			if (max < v[i])max = v[i];
			if (min > v[i])min = v[i];
			if (max - min > mid) {
				min = max = v[i];
				res++;
			}
		}
		if (res > m)
			left = mid + 1;
		else
			right = mid - 1;
	}
	cout << left;

	return 0;
}
