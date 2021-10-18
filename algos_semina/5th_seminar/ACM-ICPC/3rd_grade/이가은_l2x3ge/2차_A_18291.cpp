#include <iostream>
#include <vector>
#include <algorithm>
#define MOD ((int)1e9 + 7)

using namespace std;
long long pow(int a, int b) {
	if (b == 0)return 1;

	long long res = pow(a, b / 2);
	long long res2 = res * res % MOD;
	if (b % 2 == 0)
		return res2;
	else
		return res2 * a % MOD;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0;i < n;i++) {
		int a;
		cin >> a;
		(a == 1) ? cout << "1\n" : cout << pow(2, a - 2) << "\n";
	}


	return 0;
}
