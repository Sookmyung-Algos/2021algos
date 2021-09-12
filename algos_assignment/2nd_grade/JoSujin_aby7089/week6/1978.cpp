#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int a[101];

int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0);
	int n, cnt = 0, result = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		for (int j = 1; j <= a[i]; j++) {
			if (a[i] % j == 0)
				cnt++;
		}
		if (cnt == 2)
				result++;
		cnt = 0;
	}
	cout << result;
}
