#include <iostream>
using namespace std;

int main() {
	int arr[10001];
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int start = 0, end = 0;
	int count = 0, sum = 0;
	//값들을 다 초기화해준다.
	while (true) {
		if (sum >= m)
			sum -= arr[start++];
		//sum이 m보다 크거나 같을 경우 arr[++start]를 빼준다.
		else if
			(end == n) break;
		//end가 n이랑 같으면 끝까지 왔다는 뜻이므로 break를 해준다.
		else
			sum += arr[end++];
		//sum이 m보다 작을 경우 arrend++]를 더해준다.
		if (sum == m) 
			count++;
		//sum이 m과 같을 때 count를 하나 더해준다.
	}
	cout << count;
	return 0;
}
