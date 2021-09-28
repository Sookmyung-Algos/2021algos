#include <iostream>
#include <vector>
using namespace std;

vector <int> v;
int n, t, ans[1234567];

void merge(int left, int mid, int right) {
	int i = left;
	int j = mid + 1;
	int k = left;
	if (right - left > n / t) {
		return;
	}

	while (i <= mid && j <= right) {
		if (v[i] <= v[j]) {
			ans[k++] = v[i++];
		}
		else {
			ans[k++] = v[j++];
		}
	}
	while (i <= mid) ans[k++] = v[i++];
	while (j <= right) ans[k++] = v[j++];
	for (int i = left; i <= right; i++) {
		v[i] = ans[i];
	}
}

void merge_sort(int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		merge_sort(left, mid);
		merge_sort(mid + 1, right);
		merge(left, mid, right);
	}
	
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		v.push_back(k);
	}
	cin >> t;
	merge_sort(0, n - 1);
	for (int i = 0; i < n; i++) {
		cout << v[i] << ' ';
	}
}
