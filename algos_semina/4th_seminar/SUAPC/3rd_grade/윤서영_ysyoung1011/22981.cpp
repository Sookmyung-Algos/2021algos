#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(0), cout.tie(0);

	int n;
	vector<unsigned long long> arr;
	unsigned long long k;

	cin >> n;
	cin >> k;
	for (int i = 0; i < n; i++) {
		unsigned long long t;
		cin >> t;
		arr.push_back(t);
	}
	sort(arr.begin(), arr.end());
	unsigned long long num = arr[0] * 1 + arr[1] * (n - 1);
	for (int i = n - 2; i >= 1; i--) {
		//cout << arr[0] * (n - i) + arr[n - i] * i << endl;
		num = ((num >(arr[0] * (n - i) + arr[n - i] * i)) ? num : (arr[0] * (n - i) + arr[n - i] * i));
		//cout << "num: " << num << endl;
	}
	//cout << "num:" <<num<< endl;
	if (k % num == 0) cout << k / num;
	else cout << (k / num) + 1;
}
