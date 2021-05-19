#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int size, sum, count = 0;	//수열의 크기
	cin >> size;
	vector<int> nums;

	for (int i = 0; i < size; i++) {  //size번동안 수열 입력받기
		int n;
		cin >> n;
		nums.push_back(n);
	}
	cin >> sum;   //구하고자 하는 합 입력
	sort(nums.begin(), nums.end());   //수열을 오름차순으로 정렬

	int left = 0, right = size - 1;
	while (left < right) {  //left인덱스값이 right인덱스 값보다 작을 동안 반복
		if (nums[left] + nums[right] == sum) {
			count++;
			right--;
		}
		else if (nums[left] + nums[right] > sum)
			right--;
		else	//합이 sum보다 작을 때
			left++;
	}

	cout << count;
	return 0;
}
