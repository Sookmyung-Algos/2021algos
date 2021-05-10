#include<iostream>
using namespace std;

int main(void) {
	int arr[10001];
	int n, m;
	cin >> n >> m; //n,m을 입력받음

	for (int i = 0; i < n; i++) {
		cin >> arr[i]; //입력받은 뒤 배열에 추가
	}
	int s = 0, e = 0;
	int cnt = 0, sum = 0;
	while (1) { //투포인터
		if (sum >= m) sum -= arr[s++]; //합이 크거나 같을경우 좌포인터 올리기
		else if (e == n) break; //우포인터가 끝에 도달했는데 합이 작다면 중단
		//빼서 합이 동일하게 될 경우가 없으므로
		else sum += arr[e++]; //합이 작을경우 우포인터 올리기
		if (sum == m) cnt++; //합이 같을경우 결과 cnt를 1증가
	}
	cout << cnt << '\n'; //결과출력
	return 0;
}
