#include <iostream>
using namespace std;

long long cnt = 0;
int arr[500003], tmp[500003];

void merge(int s, int e) {
	long long m = (s + e) / 2;
	int i = s, j = m + 1, k = s;
	while (i <= m && j <= e) {
		if (arr[i] <= arr[j]) tmp[k++] = arr[i++];
		else {
			tmp[k++] = arr[j++];
			cnt += m - i + 1;
		}
	}
	while (i <= m) tmp[k++] = arr[i++];
	while (j <= e) tmp[k++] = arr[j++];
	for (int i = s; i <= e; i++)
		arr[i] = tmp[i];
}

void merge_sort(int s, int e) {
	if (s == e) return;
	int m = (s + e) / 2;
	merge_sort(s, m);
	merge_sort(m + 1, e);
	merge(s, e);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	merge_sort(0, n - 1);
	cout << cnt << '\n';

	return 0;
}
