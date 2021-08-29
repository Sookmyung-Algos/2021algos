#include <iostream>
#include <algorithm>
using namespace std;

int plan[366];

int main() {
	int n, s, e;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s >> e;
		for (int j = s; j <= e; j++) plan[j]++;
	}

	int row = 0, col = 0, ans = 0;
	for (int i = 1; i <= 365; i++) {
		if (plan[i] != 0) {
			row = max(row, plan[i]);
			col += 1;
		}
		else {
			ans += row * col;
			row = 0; 
			col = 0;
		}
	}
	ans += row * col;
	cout << ans;
}
