#include <iostream>
#include <algorithm>

using namespace std;
int a[100000], b[100000];

int search(int start, int end, int target) {
	if (start > end)
		return -1;

	int mid = (start + end) / 2;

	if (a[mid] == target)
		return mid;
	else if (a[mid] > target)
		return search(start, mid - 1, target);
	else
		return search(mid + 1, end, target);
}

int main() {
	int n, m;
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}

	sort(a, a + n);

	for (int i = 0; i < m; i++) {

		int result = search(0, n - 1, b[i]);
		if (result != -1)
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}
}
