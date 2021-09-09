#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	long long tree[1000001], ans = 0, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> tree[i];
	sort(tree, tree + n);
	long long left = 0, right = tree[n - 1], mid;
	while (left <= right) {
		long long total = 0;
		mid = (left + right) / 2;
		for (int i = 0; i < n; i++) {
			if (tree[i] >= mid)
				total += (tree[i] - mid);
		}
		if (total < m)
			right = mid - 1;
		else {
			ans = max(ans, mid);
			left = mid + 1;
		}
	}
	cout << ans << "\n";
}

//안 됐던 이유: tree를 long long으로 놓고 다른 건 타입을 맞추지 않아서
