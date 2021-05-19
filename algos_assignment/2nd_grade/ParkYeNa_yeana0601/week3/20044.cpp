#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	int n, w, ans = 200001;
	vector<int> v;

	cin >> n;
	for (int i = 0; i < 2*n; i++) {
		cin >> w;
		v.push_back(w);
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < 2*n; i++) {
		ans = min(ans, v[i] + v[2* n - 1 - i]); //코딩실력 합계가 ans보다 작을때마다 초기화
	}
	cout << ans;
}
