#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t, n, m;



int main() {
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n >> m;

		vector<int>a(n);
		vector<int>b(m);

		for (int j = 0; j < n; j++)
			cin >> a[j];
		for (int k = 0; k < m; k++)
			cin >> b[k];

		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		int cnt = 0;
		for (int i = 0; i < a.size(); i++) {
			int l = 0;
			int r = b.size() - 1;

			while (l <= r) {
				int mid = (l + r) / 2;

				if (a[i] <= b[mid])
					r = mid - 1;
				else {
					l = l + 1;
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}
