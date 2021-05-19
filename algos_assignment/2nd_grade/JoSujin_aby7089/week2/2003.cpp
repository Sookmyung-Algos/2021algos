#include <iostream>
using namespace std;

int main() {
	int a[10001];
	int n, m;
	int cnt = 0, sum = 0;
	int s = 0, e = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {  
		cin >> a[i];
	}
	while (1) {
		if (sum >= m)
			sum -= a[s++];
		else if (e == n)
			break;
		else
			sum += a[e++];
		if (sum == m)
			cnt++;
	}
	cout << cnt << '\n';
}
