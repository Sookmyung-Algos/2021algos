#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int compare(int a, int b) {
	return a > b;
}
int main() {
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end(), compare);
	int sum = -1;
	for (int i = 0; i < n - 2; i++) {
		int a = v[i], b = v[i + 1], c = v[i + 2];
		if (a < b + c) {
			sum = a + b + c;
			break;
		}
	}
	cout << sum;
	return 0;
}
