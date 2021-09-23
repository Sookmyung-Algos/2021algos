#include<iostream>
#include<algorithm>
using namespace std;

int main(void) {
	int arr[100001]; 
	int n, m;
	cin >> n >> m; 

	for (int i = 0; i < n; i++) {
		cin >> arr[i]; 
	}
	int s = 0, e = 1;
	int cnt = 2000000001;
	sort(arr, arr+n);
	while (s<n) {
		if (arr[e] - arr[s] < m) {
			e++; 
			continue;
		}
		if (arr[e] - arr[s] == m) { 
			cnt = m;
			break;
		}
		cnt = min(cnt, arr[e] - arr[s]);
		s++;
		}
	cout << cnt;
	return 0;
}
