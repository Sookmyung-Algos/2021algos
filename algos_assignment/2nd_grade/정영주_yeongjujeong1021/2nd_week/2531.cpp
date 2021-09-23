#include <iostream>
#define MAX 33001
using namespace std;

int main() {
	int n, d, k, c, arr[MAX], arr_check[MAX] = { 0, },
		coupon = 0, cnt = 0, max = 0;
	cin >> n >> d >> k >> c;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (i < k - 1) arr[i + n] = arr[i];
	}

	for (int i = 0; i < n; i++) {
		int arr_check[MAX] = { 0, };
		coupon = 1; cnt = 0;
		for (int j = i; j < i + k; j++) {
			if (arr[j] == c) coupon = 0;
			if (!arr_check[arr[j]]) {
				arr_check[arr[j]] = 1;
				cnt++;
			}
		}
		if (cnt + coupon > max)
			max = cnt + coupon;
	}

	cout << max << '\n';

	return 0;
}
