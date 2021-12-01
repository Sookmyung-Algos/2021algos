#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int n;
long long card[100001];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> card[i];
	}
	sort(card, card + n);
	long long ans = card[0];
	int cnt = 1;
	long long maxCnt = 1;
	for (int i = 1; i < n; i++) {
		if (card[i] == card[i - 1]) {
			cnt++;
		}
		else cnt = 1;
		if (maxCnt < cnt) {
			maxCnt = cnt;
			ans = card[i];
		}
	}
	cout << ans;
}
