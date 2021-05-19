#include <iostream>
using namespace std;
long long road[100010] = { 0, };
long long price[100010] = { 0, };

int main() {
	int n, lowest;
	long long ans = 0;

	cin >> n;
	for (int i = 0; i < n - 1; i++)
		cin >> road[i];
	for (int i = 0; i < n; i++)
		cin >> price[i];

	lowest = price[0];
	for (int i = 0; i < n - 1; i++) {
		if (lowest > price[i])
			lowest = price[i];
		ans += road[i] * lowest;
	}
	cout << ans;
}
