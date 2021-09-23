#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
#include<string>
#include<memory.h>
using namespace std;
int main() {
	int n, x;
	int ans = 0;
	int arr[100001];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> x;
	sort(arr, arr + n);
	int low = 0;
	int high = n - 1;
	while (high >= low) {
		int mid = (arr[low] + arr[high]);
		if (mid == x) {
			ans++;
			high--;
		}
		else if (mid > x) {
			high--;
		}
		else if (mid < x) {
			low++;
		}
	}
	cout << ans;
}
