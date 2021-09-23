#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	int min_num = 0, min_sum = 200000000;
	int num[20001];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> num[i];
	sort(num, num + n);
	
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < n; j++)
			sum += abs(num[i] - num[j]);
		if (min_sum > sum) {
			min_sum = sum;
			min_num = num[i];
		}
	}
	cout << min_num;
}
