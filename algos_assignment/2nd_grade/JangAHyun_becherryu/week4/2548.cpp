//2548 대표자연수 (brute force)
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	int min_num = 0, min_sum = 200000000;
	int nums[20001];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> nums[i];
	
	sort(nums, nums + n); //대표 자연수가 두 개 이상일 경우 작은 것을 출력 (오름차순정렬)

	for (int i = 0; i < n; i++) { 
		int sum = 0;
		for (int j = 0; j < n; j++) //원소들의 차이를 sum에 누적
			sum += abs(nums[i] - nums[j]);
		if (min_sum > sum) { //sum이 최소이면 min_sum에 저장 최소를 만드는 값을 min_num에 저장
			min_sum = sum;
			min_num = nums[i];
		}
	}
	cout << min_num;
}
