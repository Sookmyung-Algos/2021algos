#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

int n;
vector<int>prime_nums;
vector<bool>check;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	check.resize(n + 1, true);
	for (int i = 2; i * i <= n; i++) {
		if (!check[i])
			continue;
		for (int j = i * i; j <= n; j += i)
			check[j] = false;
	}
	for (int i = 2; i <= n; i++) {
		if (check[i])
			prime_nums.push_back(i);
	}

	int result = 0, sum = 0, low = 0, high = 0;
	while (1) {
		if (sum >= n) {
			sum -= prime_nums[low++];
		}
		else if (high == prime_nums.size())
			break;
		else
			sum += prime_nums[high++];
		if (sum == n)
			result++;
	}
	cout << result;
	return 0;
}
