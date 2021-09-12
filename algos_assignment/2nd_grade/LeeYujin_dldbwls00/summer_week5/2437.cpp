#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	int sum = 1;
	for (int i = 0; i < n; i++) {
		if (sum < v[i]) break;
		sum += v[i];
	}
	cout << sum;
	return 0;
}
