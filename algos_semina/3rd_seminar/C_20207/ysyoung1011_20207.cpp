#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, list[367] = { 0, };
	cin >> n;
	for (int i = 0; i < n; i++) {
		int s, e;
		cin >> s >> e;
		for (int j = s; j <= e; j++)
			list[j]++;
	}
	int maxH = 0, ans = 0, k = 0;
	for (int i = 1; i <= 366; i++) {
		if (list[i] == 0) {
			ans += maxH*k;
			maxH = 0;
			k = 0;
		}
		else {
			maxH = max(maxH, list[i]);
			k++;
		}
	}
	cout << ans;
}
