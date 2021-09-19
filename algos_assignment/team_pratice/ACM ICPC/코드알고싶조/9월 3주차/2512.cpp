#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, sum = 0, m, limit = 0;
	int prov[10010];
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> prov[i];
		sum += prov[i];
	}
	sort(prov, prov + n);
	cin >> m; // 예산
	if (m >= sum)  // 요청 모두 배정 가능
		cout << prov[n - 1];
	
	else {
		int high = prov[n - 1], low = prov[0], mid;
		while (high >= low) {
			int ans = 0;
			mid = (high + low) / 2;
			
			for (int i = 0; i < n; i++) {
				if (mid >= prov[i])
					ans += prov[i];
				else
					ans += mid;
			}
			if (ans == m) {
				limit = mid;
				break;
			}
			else if (ans > m)  // 예산 초과
				high = mid - 1;
			
			else if (ans < m) {
				limit = mid;
				low = mid + 1;
			}
		}
		if (limit == 0) 
			cout << m / n;
		
		else if (prov[n - 1] > limit)
			cout << limit;
		else
			cout << prov[n - 1];
	}
}
