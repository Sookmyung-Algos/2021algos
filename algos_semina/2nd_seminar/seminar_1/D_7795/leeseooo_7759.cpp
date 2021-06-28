#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<algorithm>
using namespace std;
int t, n, m;
int a[20001],b[20001];
int search(int key,int b[]) {
	int high = m - 1;
	int low = 0;
	int cnt = 0;
	while (high >= low) {
		int mid = (high + low) / 2;
		if (key > b[mid]) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return low;
}
int main() {
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < m; i++) {
			cin >> b[i];
		}
		sort(a, a + n);
		sort(b, b + m);
		
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			cnt += search(a[i], b);
		}
		cout << cnt << "\n";
	}
}
