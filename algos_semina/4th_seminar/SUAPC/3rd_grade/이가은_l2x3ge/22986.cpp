#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		unsigned long long n, k;
		cin >> n >> k;

		unsigned long long num;
		if (k >= n)
			num = 0;
		else
			num = (n - k - 1)*(n - k) / 2;
		unsigned long long sum = n*(n+1)/2 - num;
		
		cout << sum * 4 << '\n';
	}
	return 0;
}
