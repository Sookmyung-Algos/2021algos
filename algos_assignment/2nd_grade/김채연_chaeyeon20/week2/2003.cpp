#include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace std;
void init() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
}

int main() {
	init();
	int arr[10001];
	int n, m, cnt = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int s = 0, e = 0;
	int sum = 0;
	while (1) {
		if (sum >= m) sum -= arr[s++];
		else if (e == n) break;
		else sum += arr[e++];
		if (sum == m) cnt++;
	}
	cout << cnt << endl;
	
	return 0;
}
