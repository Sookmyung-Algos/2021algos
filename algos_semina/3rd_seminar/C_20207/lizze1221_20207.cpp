#include <iostream>
using namespace std;

int sum[367] = { 0, };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int s, e;
		cin >> s >> e;
		sum[s]++; sum[e + 1]--;
	}

	int length = 0, height = 0, ans = 0;
	for (int i = 1; i < 367; i++) {
		sum[i] += sum[i - 1];
		if (sum[i] == 0) {
			if (length == 0) continue;
			ans += length*height;
			length = 0; height = 0;
		}
		else {
			if (length == 0) {
				length = 1; height = sum[i];
			}
			else {
				length++; height = max(height, sum[i]);
			}
		}
	}
	cout << ans << "\n";

	return 0;
}
