#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, x;
	cin >> n;
	vector<int> a, v;
	for (int i = 0; i < n; i++) {
		cin >> x;
		a.push_back(x);
	}

	for (int i = 0; i < n; i++) {
		// a[i]가 v의 마지막 원소보다 큰 경우
		if (v.empty() || v.back() < a[i])
			v.push_back(a[i]);
		// a[i]가 v의 마지막 원소보다 작거나 같은 경우
		else v[lower_bound(v.begin(), v.end(), a[i]) - v.begin()] = a[i];
	}
	
	// v의 원소들이 실제 증가 수열과 같지는 않음
	cout << v.size() << '\n';

	return 0;
}
