#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;

int main() {
	int n, arr[MAX], x, sum = 0, l, r, cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cin >> x;

	sort(arr, arr + n);

	l = 0; r = n - 1;
	while (l < n && r >= 0) {
		if (arr[l] + arr[r] > x) r--;
		else if (arr[l] + arr[r] < x) l++;
		else { // arr[l] + arr[r] == x
			cnt++;
			l++;
		}
	}
	cout << cnt / 2 << '\n';
	return 0;
}
