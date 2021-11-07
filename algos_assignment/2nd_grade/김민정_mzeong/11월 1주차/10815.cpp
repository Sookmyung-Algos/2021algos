#include <iostream>
#include <algorithm>
using namespace std;
int card[500000];

bool bs(int n, int target) {
	int left = 0, right = n - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (target == card[mid]) return true;
		else if (target < card[mid]) right = mid - 1;
		else left = mid + 1;
	}
	return false;
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> card[i];
	}
	sort(card, card + n);
	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		int target; cin >> target;
		if (bs(n, target)) cout << 1;
		else cout << 0;
		cout << " ";
	}
}
