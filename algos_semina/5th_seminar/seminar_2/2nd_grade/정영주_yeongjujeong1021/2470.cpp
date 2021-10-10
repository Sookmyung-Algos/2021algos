#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

int arr[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);

	int i = 0, j = n - 1, ans = 2000000001, a = 0, b = 0;
	while (i < j) {
		int sum = arr[i] + arr[j];
		if (abs(sum) < ans) { 
			ans = abs(sum);
			a = i; b = j;
			if (ans == 0) break;
		}

		if (sum < 0) i++;
		else j--;
	}

	cout << arr[a] << ' ' << arr[b] << '\n';

	return 0;
}
