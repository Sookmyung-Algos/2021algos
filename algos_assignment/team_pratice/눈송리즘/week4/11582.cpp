#include<iostream>

using namespace std;

int arr[1050000], tmp[1050000];
int n, k;

void merge(int start, int end) {
	if (end - start > n / k)
		return;
	int mid = (start + end) / 2;
	int i = start, j = mid + 1, k = 0;

	while (i <= mid && j <= end) {
		if (arr[i] <= arr[j]) {
			tmp[k++] = arr[i++];
		}
		else
			tmp[k++] = arr[j++];
	}
	while (i <= mid)
		tmp[k++] = arr[i++];
	while (j <= end)
		tmp[k++] = arr[j++];

	for (int i = start; i <= end; i++) {
		arr[i] = tmp[i - start];
	}
}

void merge_sort(int start, int end) {
	if (start == end)
		return;

	int mid = (start + end) / 2;
	merge_sort(start, mid);
	merge_sort(mid + 1, end);
	merge(start, end);
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> k;

	merge_sort(0, n-1);

	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
	return 0;
}
