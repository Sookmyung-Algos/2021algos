#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	int nums[20001];
	cin >> n;
	for (int i = 0; i < n; i++) cin >> nums[i]; //입력받고 배열로 저장
	sort(nums, nums + n);//정렬
	cout << nums[(n - 1) / 2]; //중앙값 출력
}
