#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	int nums[20001];
	cin >> n; //자연수의 개수 n 입력
	for (int i = 0; i < n; i++)
		cin >> nums[i];
	sort(nums, nums + n); //nums배열 정렬
	cout << nums[(n - 1) / 2]; //다른 자연수들과의 차이의 합이 가장 작으려면 크기순으로 정렬했을 때 가운데 값으로 빼야 하므로 중앙값 출력
}
