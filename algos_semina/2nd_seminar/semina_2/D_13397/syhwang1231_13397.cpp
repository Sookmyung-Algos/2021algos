#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;  // n: 배열 크기, m: 구간 최대 개수

bool calc(vector<int>& arr, int mid);

int main(void) {
	cin >> n >> m;
	vector<int> arr(n);
	
	for (int i = 0; i < n; i++)  // 배열 입력
		cin >> arr[i];

	int right = *max_element(arr.begin(),arr.end());  // 벡터내의 최댓값을 right의 초기값으로
	int left = 0;
	int ans = right;

	// 이분 탐색
	while (left <= right) {
		int mid = (left + right) / 2;  // mid는 각 구간의 점수의 최댓값 중 최솟값

		if (calc(arr, mid)) {  // 나눠진 구간이 유효하다면
			if (ans > mid)
				ans = mid;  // 최솟값 갱신
			right = mid - 1;  // 
		}
		else
			left = mid + 1;
	}

	cout << ans;

	return 0;
}

bool calc(vector<int>& arr, int mid) {
	int numOfSection = 1;  // 구간의 개수의 초깃값은 1
	int max = arr[0];  // 어떤 구간의 최댓값과 최솟값은 임의로 0번째 원소로 지정
	int min = arr[0];

	for (int i = 1; i < n; i++) {
		if (arr[i] < min)  // 최솟값 갱신
			min = arr[i];
		if (arr[i] > max)  // 최댓값 갱신
			max = arr[i];

		if ((max - min) > mid) {  //구간의 점수(최댓값-최솟값)가 현재 mid값보다 크다면 
			numOfSection++;  // 구간 개수 1 증가
			min = arr[i];  // i번째 원소를 다시 최댓값, 최솟값으로 지정
			max = arr[i];
		}
	}
	return numOfSection <= m;  // 나눠진 구간의 개수가 유효한지에 대해 리턴
}
