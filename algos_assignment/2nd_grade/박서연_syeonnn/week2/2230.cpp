#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n, m, gap, result= 2000000000;
	int s = 0, e = 1;
	int arr[100001];

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	} // 수열 입력받기

	sort(arr, arr + n); // 수열 정렬

	while ( s < n ) {
		if (arr[e] - arr[s] < m) { // 두 수의 차가 m보다 작을 때
			e++;
			continue;
		} // 끝 인덱스 1씩 증가
		if (arr[e] - arr[s] >= m) { // 두 수의 차가 m보다 크거나 같을 때
			result = min(result, arr[e] - arr[s]);
			s++;
		} // 최솟값을 result에 저장, 시작 인덱스 1씩 증가
	}

	cout << result;
}
