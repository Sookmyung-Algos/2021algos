#include<iostream>

using namespace std;

int list[1001];
int arr[1001];

int binarysearch(int left, int right, int key) {
	while (left <= right) {
		int mid = (left + right) / 2;

		if (list[mid] < key)
			left = mid + 1;
		else
			right = mid-1;
	}
	return left;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	list[0] = arr[0];

	int j = 0;
	for (int i = 1; i < n; i++) {
		if (list[j] < arr[i]) {
			list[++j] = arr[i];
		}
		else {
			int idx = binarysearch(0, j, arr[i]);
			list[idx] = arr[i];
		}
	}

	cout << j+1 << '\n';
	return 0;
}
