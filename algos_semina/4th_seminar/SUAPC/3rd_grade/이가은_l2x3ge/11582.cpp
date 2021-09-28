#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int a[1500000], b[1500000];
void sort(int start, int end);
void merge(int start, int end);
int n, time;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;

	for (int i = 0;i < n;i++) {
		cin >> a[i];
	}
	cin >> time;
	//cout << ;
	sort(0, n - 1);
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	return 0;
}

void sort(int start, int end) {
	if (start == end) {
		return;
	}
	int mid = (start + end) / 2;
	sort(start, mid);
	sort(mid + 1, end);
	merge(start, end);
}
void merge(int start, int end) {
	if (end - start + 1 > n / time)
		return;
	int mid = (start + end) / 2;
	int i = start, j = mid + 1, k = 0;
	while (i <= mid && j <= end) {
		if (a[i] <= a[j]) {
			b[k++] = a[i++];
		}
		else {
			b[k++] = a[j++];
		}
	}
	while (i <= mid) b[k++] = a[i++];
	while (j <= end) b[k++] = a[j++];
	for (int i = start; i <= end; i++) {
		a[i] = b[i - start];
	}
}
