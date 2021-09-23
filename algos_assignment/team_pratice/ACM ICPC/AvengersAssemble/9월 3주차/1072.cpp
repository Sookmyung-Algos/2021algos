#include<iostream>
#define MAX 1000000000
using namespace std;

long long x, y;
int winRate;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> x >> y;
	winRate = (y * 100) / x;
	if (winRate >= 99) {
		cout << -1;
		return 0;
	}

	int low = 0, high = MAX;
	int ans = -1;

	while (low <= high) {
		int mid = (low + high) / 2;
		int temp = (100 * (y + mid)) / (x + mid);

		if (winRate >= temp) {
			ans = mid + 1;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	cout << ans << "\n";
	return 0;
}
