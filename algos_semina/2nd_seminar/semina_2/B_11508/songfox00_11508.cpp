#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int>v;

bool cmp(int a, int b) {
	if (a > b)
		return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end(),cmp);

	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (i % 3 != 2)
			sum += v[i];
	}
	cout << sum;
	return 0;
}
