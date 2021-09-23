#include <iostream>
using namespace std;
#define MAX 10000

int main() {
	int arr[MAX], n, m, cnt = 0, l = 0, r = 0, sum = 0;

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	while (1) {
		if (sum >= m) sum -= arr[l++];
		else if (r == n) break;
		else sum += arr[r++];

		if (sum == m) cnt++;
	}
	cout << cnt << '\n';

	return 0;
}
