#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
using namespace std;
void init() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
}


int n, c;
int arr[200002];

int main() {
	init();

	int ret = 0;
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	int end = arr[n - 1], start = 0, mid;
	int cnt, i;
	while (start<=end) {
		mid = (start + end) / 2;
		i = 0;
		cnt = 1;
		for (int x = 0; x < n; x++) {
			if (arr[x] - arr[i] >= mid) {
				i = x;
				cnt++;
			}
			
		}
		if (cnt >= c) {
			if (ret < mid) ret = mid;
			start = mid + 1;
		}
		else end = mid - 1;
	}
	cout << ret;
	return 0;
}
