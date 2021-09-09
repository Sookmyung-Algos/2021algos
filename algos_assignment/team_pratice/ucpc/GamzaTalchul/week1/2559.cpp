#include <iostream>
#include <algorithm>
#include <vector>
#define M 100001
using namespace std;

int main() {
	int arr[M] = { 0, };
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int total = 0, ans = -1000000;
	for (int i = 0; i < n - k + 1; i++) {
		if (i == 0) {
			for (int j = 0; j < k; j++)
				total += arr[j];
		}
		else {
			total -= arr[i - 1];
			total += arr[i + k - 1];
		}
		if (total > ans)
			ans = total;
	}
	cout << ans << "\n";
}
