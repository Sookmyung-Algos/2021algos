#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstdio>
#include <functional>

using namespace std;

int num[100005];

long long solve(int l, int r) {
	if (l == r) {
		return (long long)num[l] * num[l];
	}
	else if (l < r) {
		int m = (l + r) / 2;

		long long score = max(solve(l, m), solve(m + 1, r));

		int ml = m;
		int mr = m + 1;

		int tempMin = min(num[ml], num[mr]);
		long long tempSum = num[ml] + num[mr];
		long long tempMaxScore = (long long)tempSum * tempMin;

		while (ml > l || mr < r) {
			if (ml > l && (mr == r || num[ml - 1] > num[mr + 1])) { //왼쪽으로
				tempMin = min(tempMin, num[--ml]);
				tempSum += num[ml];
			}
			else { //오른쪽으로
				tempMin = min(tempMin, num[++mr]);
				tempSum += num[mr];
			}
			tempMaxScore = max(tempMaxScore, (long long)tempSum * tempMin);
		}

		score = max(score, tempMaxScore);

		return score;
	}
	else {
		return 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	cout << solve(0, n - 1);

	return 0;
}
