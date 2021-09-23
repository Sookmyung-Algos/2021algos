#include<iostream>
using namespace std;

int main(void) {
	long long arr[100001]; //int일때 오버플로우가 나서 long long으로 교체했습니다
	int n, m;
	cin >> n >> m; 

	for (int i = 0; i < n; i++) {
		cin >> arr[i]; 
	}
	int s = 0, e = 0;
	int cnt = 0, sum = 0;
	int size = 100001, now_size;
	while (1) { //투포인터
		if (sum >= m) sum -= arr[s++];
		else if (e == n) break;
		else sum += arr[e++];
		if (sum >= m) {
			now_size = e - s;
			if (size > now_size) {
				cnt = now_size;
				size = now_size;
			};
		}
	}
	cout << cnt << '\n';
	return 0;
}
