#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	int min_num = 0, min_sum = 200000000;
	int nums[20001];
	cin >> n;

	sort(nums, nums + n);
	cout << nums[(n - 1) / 2];

	return 0;
}
