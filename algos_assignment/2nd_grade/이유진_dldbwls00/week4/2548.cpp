#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) cin >> arr[i];

	sort(arr, arr + n); // 정렬

	//주어진 모든 자연수들에 대하여 그 차이 전체의 합을 최소로 하는 자연수는 중앙값이다.
	cout << arr[(n - 1) / 2];
	return 0;
}
