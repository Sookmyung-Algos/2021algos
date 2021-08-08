#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int d[366] = { 0, }; //main 내에 넣으면 틀림..왜지?
int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0);
	int height = 0, width = 0, ans = 0;
	int s, e, n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s >> e;
		for (int j = s; j <= e; j++)
			d[j]++;
	}
	for (int i = 1; i <= 366; i++) {
		if (d[i] != 0) {
			width++;
			height = max(height, d[i]);
		}
		else {
			ans += width*height;
			width = 0, height = 0;
		}
	}
	cout << ans;
}
