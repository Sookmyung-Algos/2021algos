//헷갈림
#include <iostream>
#include <algorithm>
using namespace std;

//merge sort
int a[1048577], b[1048577];
int n, k, cnt;

void merge(int l, int r) {
	if (r - l >  n / k)	return; //인원을 만족하는 순간 정렬을 멈춤
	int mid = (l + r) / 2;
	int i = l, j = mid + 1, idx = 0;
	while (i <= mid && j <= r) {
		if (a[i] <= a[j])	b[idx++] = a[i++];
		else b[idx++] = a[j++];
	}
	while (i <= mid)	b[idx++] = a[i++];
	while (j <= r)	b[idx++] = a[j++];
	for (int i = l; i <= r; i++)	a[i] = b[i - l];
}
void merge_sort(int l, int r) {
	if (l == r)	return;
	int mid = (l + r) / 2;
	merge_sort(l, mid);
	merge_sort(mid + 1, r);
	merge(l, r);
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> a[i];
	cin >> k;
	merge_sort(0, n - 1);
	for (int i = 0; i < n; i++)	cout << a[i] << " ";
	return 0;
}
