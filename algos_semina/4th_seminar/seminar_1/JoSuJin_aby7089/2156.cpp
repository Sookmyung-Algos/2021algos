#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int n, a[10001], d[10001];

int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	d[1] = a[1];  
	d[2] = a[1] + a[2];
	if (n >= 3) {   //n이 3 이상일 때 점화식=> d[i] = max(d[i-1], d[i-2]+a[i], d[i-3]+a[i-1]+a[i])
		for (int i = 3; i <= n; i++) {
			d[i] = d[i - 1];
			if (d[i] < d[i - 2] + a[i])
				d[i] = d[i - 2] + a[i];
			if (d[i] < d[i - 3] + a[i - 1] + a[i])
				d[i] = d[i - 3] + a[i - 1] + a[i];
		}
	}
	cout << d[n];
}
