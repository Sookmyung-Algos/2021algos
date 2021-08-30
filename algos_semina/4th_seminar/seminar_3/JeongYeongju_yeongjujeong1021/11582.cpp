#include <iostream>
using namespace std;

int num[1048577];
int tmp[1048577];
int n, k;

void merge(int l, int r) {
	int m = (l + r) / 2;
	int i = l, j = m + 1, k = 0;

	while (i <= m && j <= r) {
		if (num[i] <= num[j]) tmp[k++] = num[i++];
		else tmp[k++] = num[j++];
	}

	while (i <= m) tmp[k++] = num[i++];
	while (j <= r) tmp[k++] = num[j++];

	for (int i = l; i <= r; i++) num[i] = tmp[i - l];
} 

void merge_sort(int l, int r) {
	int m;
	if (l < r) {
		m = (l + r) / 2;
		merge_sort(l, m);
		merge_sort(m + 1, r);
		if (r - l <= n / k)
			merge(l, r);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> num[i];
	cin >> k;
	merge_sort(0, n - 1);

	for (int i = 0; i < n; i++)
		cout << num[i] << ' ';

	return 0;
}
