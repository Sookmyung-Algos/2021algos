#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, w, ans = 200001;
	vector<int> v;

	cin >> n;
	for (int i = 0; i < 2 * n; i++) {
		cin >> w;
		v.push_back(w);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < 2 * n; i++) //가장 작은 값과 두번째로 큰 값의 합과 원래 값 중 min값 찾기.
		ans = min(ans, v[i] + v[2*n - 1 - i]);

	cout << ans;
}
