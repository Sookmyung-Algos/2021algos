#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int main() {
	int n, m,num;
	int a[1000002], b[1000002],c[2000004];
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		scanf("%d ", &a[i]);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d ", &b[i]);
	}
	int i = 0, j=0, k = 0;
	while (i < n && j < m) {
		if (a[i] <= b[j]) {
			c[k++] = a[i++];
		}
		else {
			c[k++] = b[j++];
		}
	}
	while (i < n) {
		c[k++] = a[i++];
	}
	while (j < m) {
		c[k++] = b[j++];
	}
	for (int i = 0; i < n + m; i++) {
		printf("%d ", c[i]);
	}
	return 0;
}
