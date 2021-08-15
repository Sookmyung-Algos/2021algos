#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n;
string a[1000];

int integer_sum(string a) {
	int len = a.length();
	int sum = 0;
	for (int i = 0; i < len; i++) {
		if (a[i] - '0' <= 9 && a[i] - '0' >= 0) {
			sum += a[i] - '0';
		}
	}
	return sum;
}

bool cmp(string a, string b) {
	if (a.length() < b.length()) {
		return 1;
	}
	else if (a.length() > b.length()) {
		return 0;
	}
	else {
		int sum_a = integer_sum(a);
		int sum_b = integer_sum(b);
		if (sum_a < sum_b) {
			return 1;
		}
		else if (sum_a > sum_b) {
			return 0;
		}
		else {
			return a < b;
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n, cmp);
	for (int i = 0; i <n; i++) {
		cout << a[i] << ' '<<endl;
	}
    return 0;
}
