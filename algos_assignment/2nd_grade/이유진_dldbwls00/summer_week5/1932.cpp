#include <iostream>
#include <algorithm>
using namespace std;

int tri[501][501];
int sum = 0;
int main(void) {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j)	cin >> tri[i][j];
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j)	tri[i][j] += max(tri[i - 1][j - 1], tri[i - 1][j]);
	}

	for (int i = 1; i <= n; i++) {
		if (sum < tri[n][i]) sum = tri[n][i];
	}

	cout << sum << "\n";
} //복습
