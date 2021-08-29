#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, a, b;
	int min_a = 366;
	int max_b = 0;
	int max_num = 0;
	int sum = 0;
	vector<int> v(1001,0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		for (int j = a; j <= b; j++) {
			v[j] += 1;
		}
		min_a = min(min_a, a);
		max_b = max(max_b, b);
	}
	for (int i = min_a; i <= max_b+1; i++) {
		if (v[i] == 0) {
			max_num = 0;
			for (int j = i; j >= min_a; j--) {
				max_num = max(max_num, v[j]);
			}
			sum = sum + max_num*(i - min_a);
			min_a = i+1;
		}
	}
	cout << sum;
}
