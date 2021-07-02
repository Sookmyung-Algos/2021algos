#include <iostream>
#define MAX 4000001
using namespace std;

int arr[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(); cout.tie();

	int n, k, x, g, right = 0, sum = 0, max_num = 0;

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> g >> x;
		arr[x] = g;
		right = max(right, x);
	}

	for (int i = 0; i <= 2 * k; i++) {
		sum += arr[i];
	}

	int i = 0, j = 2 * k + 1;
	while (1) {
		max_num = max(max_num, sum);
		if (j == right|| j == MAX) break;
		sum -= arr[i++];
		sum += arr[j++];
	}

	cout << max_num << '\n';

	return 0;
}
