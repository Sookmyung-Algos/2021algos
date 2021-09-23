#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	int nums[20001];
	cin >> n;
	for (int i = 0; i< n; i++) cin >> nums[i];
	sort(nums, nums+n);
	cout << nums[(n-1)/2];
}
