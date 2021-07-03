#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int  n, m, k;
		cin >> n >> m;
		int a[20001], b[20001];

		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < m; i++) cin >> b[i];

		sort(a, a + n); sort(b, b + m);


		int num = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (b[j]<a[i]) num++;
				else break;
			}
		}
		cout << num << '\n';
	}
}
