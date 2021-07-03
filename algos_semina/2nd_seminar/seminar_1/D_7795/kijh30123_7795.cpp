#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;

int t, n, m, a, b, ans;

int main(void)
{
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL); //입출력속도 개선
	
	cin >> t;
	for (int i = 0; i < t; i++) {
		ans = 0;
		cin >> n >> m;
		vector<int> arrA;
		for (int j = 0; j < n; j++) {
			cin >> a;
			arrA.push_back(a);
		}
		vector<int> arrB;
		for (int r = 0; r < m; r++) {
			cin >> b;
			arrB.push_back(b);
		}
		sort(arrB.begin(), arrB.end());
		sort(arrA.begin(), arrA.end(), greater<>());
		for (int j = 0; j < n; j++) {
			for (int r = 0; r < m; r++) {
				if (arrA[j] > arrB[r]) {
					ans++;
				}
				else {
					break;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
