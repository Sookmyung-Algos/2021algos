#include <iostream>
using namespace std;
#define MAX 100001

int main() {
	int n, s, arr[MAX], l = 0, r = 0, sum = 0, len = 0, min = 0;
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	while (1) {
		if (sum >= s) {
			sum -= arr[l++];
			len--;
		}
		else if (r == n) break;
		else {
			sum += arr[r++];
			len++;
		}

		if (sum >= s) {
			if (min == 0 || len < min)
				min = len;
		}
	}

	cout << min << '\n';

	return 0;
}
