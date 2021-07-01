#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 20001;
int a[MAX], b[MAX];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	int t, n, m;

	cin >> t;
	for (int i = 0; i < t; i++) {
		int ans = 0;

		cin >> n >> m;

		for (int j = 0; j < n; j++) {
			scanf("%d", &a[j]);
		}
		for (int j = 0; j < m; j++) {
			scanf("%d", &b[j]);
		}
		sort(a, a + n, cmp);
		sort(b, b + m, cmp);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i] > b[j]) {
					ans += (m - j);
					break;
				}
			}
		}
		cout << ans << '\n';
	}
}
