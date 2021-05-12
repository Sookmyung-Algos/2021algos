#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, m, j = 0;
	int ans = 2000000001;
	cin >> n >> m;
	int a[100001];
	for (int i = 0; i < n;i++) 
		cin >> a[i];
	sort(a, a + n);  //받은 수열을 오름차순으로 정렬
	int s = 0, e = 0;
	int cnt = 0, dif = 0;
	while (s<=e&&e<n) {      
		dif = a[e] - a[s];
		if (dif >= m) {           
			ans = min(ans, dif);  //m보다 크거나 같은 차 중에서 최솟값 구하기
			s++;
		}
		else {
			e++;
		}
	}
	cout << ans;
}
