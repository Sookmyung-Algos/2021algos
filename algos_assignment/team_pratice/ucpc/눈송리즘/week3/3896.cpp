#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int check[1300001];
vector<int>v;

void makePrime() {
	for (int i = 2; i <= sqrt(1300000); i++) {
		if (!check[i]) {
			for (int j = i*i; j <= 1300000; j += i)
				check[j] = 1;
		}
	}
	for (int i = 1; i <= 1300000; i++) {
		if (!check[i])
			v.push_back(i);
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	makePrime();
	int t;
	cin >> t;

	while (t--) {
		int k;
		cin >> k;

		if (!check[k]) {
			cout << 0 << '\n';
			continue;
		}

		int left = 2, right = v.size() - 1;
		while (left <= right) {
			int mid = (left + right) / 2;

			if (v[mid] < k) {
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}
		cout << v[left] - v[left - 1] << '\n';
	}
	return 0;
}
