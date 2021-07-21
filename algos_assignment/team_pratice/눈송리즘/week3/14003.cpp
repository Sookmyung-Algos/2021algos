#include<iostream>
#include<algorithm>

using namespace std;

int list[1000001];
int arr[1000001];
int index[1000001];

int binarysearch(int left, int right, int key) {
	while (left <= right) {
		int mid = (left + right) / 2;

		if (list[mid] < key)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return left;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	list[0] = arr[0];
	int j = 0;
	index[0] = 0;

	for (int i = 1; i < n; i++) {
		if (list[j] < arr[i]) {
			list[++j] = arr[i];
			index[i] = j;
		}
		else {
			int idx=binarysearch(0, j, arr[i]);
			list[idx] = arr[i];
			index[i] = idx;
		}
	}
	
	cout << j + 1 << '\n';

	int ans[1000001];
	int len = j;
	int k = 0;

	for (int i = n-1; i >= 0; i--) {
		if (index[i] == len) {
			ans[k++] = arr[i];
			len--;
		}
	}
	
	for (int i = k-1; i >=0; i--) {
		cout << ans[i] << ' ';
	}

	return 0;
}
