#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

int main()
{
	int n, k, coin;
	int cnt = 0;
	vector<int> v;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> coin;
		v.push_back(coin);
	}

	sort(v.begin(), v.end(), greater<int>());

	for (int i = 0; i < n; i++) {
		if (k >= v[i] && k != 0) {
			while (1) {
				k -= v[i];
				cnt++;
				if (k < v[i]) break;
			}
		}
		if (k == 0) {
			cout << cnt;
			return 0;
		}
	}
}
