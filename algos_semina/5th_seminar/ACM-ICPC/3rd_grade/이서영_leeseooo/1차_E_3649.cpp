#include <iostream>
#include <algorithm>
using namespace std;
int x, n;
int arr[1000001];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	while (cin >> x) {
		cin >> n;
		x *= 10000000;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		sort(arr, arr + n);
		int low = 0; int high = n - 1;
		int sum = 0;
		while (high > low) {
			sum = arr[low] + arr[high];
			if (sum < x) {
				low++;
			}
			else if (sum > x) {
				high--;
			}
			else {
				break;
			}
		}
		if (sum == x)cout << "yes " << arr[low] << ' ' << arr[high] << '\n';
		else cout << "danger\n";
	}
}
