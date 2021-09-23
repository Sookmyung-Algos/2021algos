#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int n, m, l;

bool sol(int d) {
	int cnt = 0;
	for (int i = 1; i < v.size(); i++) { // v.size = n + 2
		int temp = v[i] - v[i - 1];
		cnt += temp / d;
		if (temp / d != 0 && temp % d == 0) cnt--; 
	}
	if (cnt <= m) return true;
	else return false;
}
int main() {
	cin >> n >> m >> l;

	v.push_back(0);
	for (int i = 0; i < n; i++) {
		int input; cin >> input;
		v.push_back(input);
	}
	v.push_back(l);
	sort(v.begin(), v.end());

	int mx = 0;
	for (int i = 1; i < v.size(); i++) mx = max(mx, v[i] - v[i - 1]);
	
	int s = 1, e = mx; // DivisionByZero
	int ans = mx;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (sol(mid)) {
			ans = min(ans, mid);
			e = mid - 1;
		}
		else s = mid + 1;
	}
	cout << ans;
}
