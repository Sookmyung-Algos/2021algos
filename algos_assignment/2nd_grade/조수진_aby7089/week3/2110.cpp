#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int x[200000];
	int n, c;
	cin >> n >> c;
	for (int i = 0; i < n; i++) 
		cin >> x[i];
	sort(x, x + n);
	int l = 1, r = x[n - 1] - x[0];  //최소거리는 1이고, 최대거리는 맨 처음집과 마지막 집 사이 거리임
	int i = 1, num;
	int result = 0;
	while (l <= r) {
		int cnt = 1;
		int prev = x[0];
		int mid = (l + r) / 2;
		for (int j = 1; j < n; j++) {
			if (x[j] - prev >= mid) {  //공유기 설치
				cnt++;
				prev = x[j];
			}
		}
		if (cnt >= c) {  //설치된 공유기가 많음-간격 넓히기
			result = max(result, mid);
			l = mid + 1;
		}
		else            //설치된 공유기가 적음-간격 좁히기
			r = mid - 1;
	}
	cout << result;
}
