#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int>num;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int check = 0;

	cin >> n;
	num.resize(n * n + 1);

	for (int i = 0; i < n * n; i++) {
		cin >> num[i];
	}

	sort(num.begin(), num.end());

	int pos;

	for (int i = 0; i <= n * n; i++) {

		if (num[i] == 0) {
			pos = i;
		}
		//cout << "i: " << i << "  : " << num[i] << "\n";
	}

	if (pos >= n * n - n + 1) {
		check = 1;
	}

	cout << num[n * n - n + 1 - check];

}
