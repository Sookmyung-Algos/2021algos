#include <iostream>
using namespace std;

int A[500000], tmp[500000];
long long swapcnt;

void merge(int s, int e) {
	int mid = (s + e) / 2;
	int i = s, j = mid + 1;
	int idx = 0;
	while (i <= mid || j <= e) {
		if (i <= mid && (j > e || A[i] <= A[j])) tmp[idx++] = A[i++];
		else {
			tmp[idx++] = A[j++];
			swapcnt += (long long)mid - i + 1;
		}
	}
	for (int i = s; i <= e; i++) A[i] = tmp[i - s];
}

void merge_sort(int s, int e) {
	if (s == e) return;
	int mid = (s + e) / 2;
	merge_sort(s, mid);
	merge_sort(mid + 1, e);
	merge(s, e);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i];
	merge_sort(0, n - 1);
	cout << swapcnt;
}
