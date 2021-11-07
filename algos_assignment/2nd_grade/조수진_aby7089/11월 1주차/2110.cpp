#include <iostream>
#include <algorithm>
using namespace std;
int house[200001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, c;
	cin >> n >> c;
	for (int i = 0; i < n; i++) 
		cin >> house[i];
	sort(house, house + n);
	int l = 1, r = house[n - 1] - house[0];  //가장 먼 두 공유기의 차이
	int i = 1, num, result = 0;
	while (l <= r) {
		int cnt = 1;
		int prev = house[0];
		int mid = (l + r) / 2;
		for (int j = 1; j < n; j++) {
			if (house[j] - prev >= mid) {
				cnt++;
				prev = house[j];
			}
		}
		if (cnt >= c) {
			result = max(result, mid);
			l = mid + 1;
		}
		else
			r = mid - 1;
	}
	cout << result;
}
