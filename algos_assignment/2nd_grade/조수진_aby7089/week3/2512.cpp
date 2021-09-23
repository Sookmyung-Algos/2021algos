#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a[10001];
	int n, maxn = 0, m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		maxn = max(maxn, a[i]);
	}
	sort(a, a + n);
	cin >> m;
	int high = maxn, low = 0;  //최댓값을 예산요청을 받은 값 중 가장 큰 것으로 설정
	int mid, sum;
	int result;
	while (low <= high) {
		sum = 0;
		mid = (low + high) / 2;
		for (int i = 0; i < n; i++)
			sum += min(a[i], mid);
		if (sum <= m) {  //총액을 넘지 않는 경우
			result = mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	cout << result;
}
