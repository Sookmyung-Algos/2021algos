#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<memory.h>
using namespace std;
int t,n;
long long arr[1000001];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		long long max_cost = arr[n - 1]; //최대 주가
		long long max_profit = 0; //최대 이윤
		for (int i = n - 1; i >= 0; i--) {
			if (max_cost < arr[i])max_cost = arr[i]; //최대주가 갱신
			else if (max_cost > arr[i]) {
				max_profit += max_cost - arr[i];
			}
		}
		cout << max_profit << '\n';
	}
}
