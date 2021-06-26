#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int t;
	cin >> t;
	for (int i = 0;i < t;i++) {
		int a[20001];
		int b[20001];
		int n, m, result=0;
		cin >> n >> m;
		for (int x = 0;x < n;x++) {
			cin >> a[x];
		}
		for (int x = 0;x < m;x++) {
			cin >> b[x];
		}
		sort(a, a + n, greater<>());
		sort(b, b + m, greater<>());
		for (int x = 0;x < n;x++) {
			for (int y = 0;y < m;y++) {
				if (a[x] > b[y]) {
					result += m - y;
					break;
				}
			}
		}

		cout << result << "\n";
	}
}
