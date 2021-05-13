#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
int arr[1000000];

int main() {
	int n;
	int cnt = 0;
	int x;
	cin >> n;
	for (int i = 0; i < n; i ++ ) {
		cin >> arr[i];
	}
	cin >> x;
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		int e = n - 1;
		int s = 0;
		while (s <= e) {
			int m = (s + e) / 2;
			if (arr[m] == x - arr[i]) {
				cnt++;
				break;
			}
			else if (arr[m] < x - arr[i]) {
				s = m + 1;
			}
			else e = m - 1;
		}
			

	}
	cout << cnt / 2;
	return 0;
}
