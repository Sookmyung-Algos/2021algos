#include <iostream>
using namespace std;

int main() {
	int arr[10001];
	int n, m; // 수열의 숫자 개수 n, 합해서 되는 수 m
	int cnt = 0, sum = 0; // sum에서 부분합을 계산함

	cin >> n >> m;
	for (int i = 0; i < n; i++)	cin >> arr[i]; //수열을 배열에 저장
	
	int s = 0, e = 0; // 투포인터 초기화

	while (1) {
		if (sum >= m)	sum -= arr[s++]; //포인터s는 부분합에서 앞쪽숫자를 뺌
		else if (e == n)	break; //수열의 끝
		else sum += arr[e++]; //포인터e는 부분합에 뒷쪽숫자를 추가

		if (sum == m)	cnt++; // 경우의 수 count
	}
	cout << cnt;
	return 0;
}
