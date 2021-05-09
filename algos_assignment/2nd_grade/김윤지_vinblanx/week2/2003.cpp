#include <iostream>

using namespace std;

int main() {
	int N, M;
	int start = 0, end = 0, cnt = 0, sum = 0;
	cin >> N >> M;
	int arr[10001];

	for (int i = 0; i < N; i++) {
		cin >> arr[i]; //N개의 수를 가진 수열 받기
	}
	
	while (start <= end) {
		if (sum >= M || end == N) //부분합이 M 이상이거나, 이미 e가 N과 같은 경우
			sum -= arr[start++]; //start 증가시킨 뒤에 부분합은 해당 값을 뺀 값으로 저장해서 부분합이 M이 되는 값을 다시 찾도록 함
		else //부분합이 M 이상이 아니거나, e가 N이 아닐 때에는
			sum += arr[end++]; //end 증가시킨 뒤에 해당 값을 부분합에 더하여 부분합이 M이 되는 값을 찾도록 함
		if (sum == M) //현재 부분합이 M과 같다면 cnt 값 증가시켜서 개수 세기
			cnt++;
	}

	cout << cnt << '\n';
}
